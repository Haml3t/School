"""grader.py: Grades a student lab and outputs the result."""

__author__ = 'Milinda Perera (mail@milinda-perera.com)'

import glob
import os
import subprocess
import time

case_pattern = 'test_data/case*'
case_delimiter = '@\n'
computed_output_file_name = 'output_computed.txt'
required_output_file_name = 'output_required.txt'
solution_cmd = './solution'
make_cmd = 'make'
clean_cmd = 'clean_all'
title_pattern = '-'
line_width = 100
sleep_seconds = 0.2
too_long_seconds = 5


def get_title(title, title_width):
    return '{0:{1}^{2}}'.format(' %s ' % title, title_pattern, title_width)


def build_solution():
    output = [get_title('Builder Output', line_width)]
    try:
        build_process = subprocess.Popen(make_cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        output.append(build_process.communicate()[0])
    except subprocess.CalledProcessError as ex:
        raise Exception('Unable to build solution:\n{0}'.format(ex.output))
    return '\n'.join(output)


def clean_solution():
    subprocess.check_call([make_cmd, clean_cmd])


def test_solution():
    case_file_paths = sorted(glob.glob(case_pattern))
    output = []
    for case_file_path in case_file_paths:
        try:
            end_time = time.time() + too_long_seconds
            solution_process_args = [solution_cmd, case_file_path]
            solution_process = subprocess.Popen(solution_process_args, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
            while time.time() < end_time and solution_process.poll() is None:
                time.sleep(sleep_seconds)
            if solution_process.poll() is None:
                solution_process.kill()
                raise subprocess.CalledProcessError(
                    1, ' '.join(solution_process_args), 'Testing takes too long, infinite loop?')
            else:
                output.append(solution_process.communicate()[0])
        except subprocess.CalledProcessError as ex:
            output.append('Unable to test {0}:\n{1}'.format(case_file_path, ex.output))
    with open(computed_output_file_name, 'w') as computed_output_file:
        computed_output_file.write(case_delimiter.join(output))


def grade_solution():
    with open(required_output_file_name) as required_output_file:
        required_case_results = required_output_file.read().split(case_delimiter)
    with open(computed_output_file_name) as computed_output_file:
        computed_case_results = computed_output_file.read().split(case_delimiter)
    is_equal_list = [required_case_results[i] == computed_case_results[i] for i in range(len(required_case_results))]
    case_file_paths = sorted(glob.glob(case_pattern))
    output = [get_title('Summary', line_width)]
    if all(is_equal_list):
        output.append('All tests passed.')
    else:
        output.append('Student output has {0} failure(s).'.format(is_equal_list.count(False)))
        output.append('Detailed Report:')
        for i in range(len(required_case_results)):
            if not is_equal_list[i]:
                output.append(get_title(case_file_paths[i], line_width / 2))
                output.append(get_title('Student Has', line_width / 4))
                output.append(computed_case_results[i])
                output.append(get_title('Should Have', line_width / 4))
                output.append(required_case_results[i])
    return is_equal_list.count(True), len(required_case_results), '\n'.join(output)


def grade_student(sandbox_dir_path='.', pre_funcs=[], post_funcs=[clean_solution], result_file_name=None):
    cwd = os.getcwd()
    os.chdir(sandbox_dir_path)
    output = []
    try:
        for pre_func in pre_funcs:
            output.append(pre_func())
        output.append(build_solution())
        test_solution()
        num_correct, num_total, grade_output = grade_solution()
        output.append(grade_output)
        grade = int(round(100.0 * num_correct / num_total))
        output.append('Score: {0} out of {1} = {2}%'.format(num_correct, num_total, grade))
    except Exception as ex:
        grade = 0
        output.append(ex.message)
        output.append(get_title('Fatal Error', line_width))
        output.append('Score: 0%')
    filter(lambda e: e.strip() != '', output)
    output_str = '\n'.join(reversed(output))
    if result_file_name:
        with open(result_file_name, 'w') as result_file:
            result_file.write(output_str)
    else:
        print output_str
    for post_func in post_funcs:
        post_func()
    os.chdir(cwd)
    return grade


if __name__ == '__main__':
    grade_student()
