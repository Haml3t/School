class application {
    public static void main(String[] args) { // main method; this is what runs when I run this program
	application crysis2 = new application();
	crysis2.setMode(0);
	crysis2.setName("Crysis 2");
	application slack_mobile = new application();
	slack_mobile.setMode(3);
	slack_mobile.setName("Slack Mobile");

	crysis2.print_app_info();
	slack_mobile.print_app_info();
	// create an application and set its mode
	// get the mode of the application with the getter function
	// display the serial number of the application with the serial method
    }

    private String mode;
    private String app_name;

    public void setMode(int mode_int) { // 1 = desktop, 2 = web, 3 = mobile desktop, 4 = mobile web
	switch (mode_int) {
	case 1: mode = "Desktop";
	    break;
	case 2: mode = "Web";
	    break;
	case 3: mode = "Mobile desktop";
	    break;
	case 4: mode = "Mobile web";
	    break;
	default: mode = "Invalid input";
	    break;
	}
    }

    public String getMode() {
	return mode;
    }

    public void setName(String name) {
	app_name = name;
    }

    public String getName() {
	return app_name;
    }

    public void print_app_info() {
	System.out.println("Application name: " + app_name + " Application mode: " + mode);
    }
}
