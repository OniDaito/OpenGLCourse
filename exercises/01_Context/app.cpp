/**
* @brief GLFW Window based solution
* @file app.hpp
* @author Benjamin Blundell <oni@section9.co.uk>
* @date 03/07/2012
*
*/

#include "app.hpp"

#include <boost/program_options.hpp>
#include <signal.h>

using namespace std;
using namespace boost;
using namespace boost::assign;
using namespace s9;
using namespace s9::gl;

namespace po = boost::program_options;


/*
 * Called when the mainloop starts, just once
 */

void BasicApp::init(){
    link(*this);
}


/*
 * Called as fast as possible. Not set FPS wise but dt is passed in
 */
		
void BasicApp::display(double_t dt){
    
}

/*
 * This is called by the wrapper function when an event is fired
 */

void BasicApp::processEvent(MouseEvent e){

}

/*
 * Called when the window is resized. You should set cameras here
 */

void BasicApp::processEvent(ResizeEvent e){
    cout << "Window Resized:" << e.mW << "," << e.mH << endl;

   
}

void BasicApp::processEvent(KeyboardEvent e){
    cout << "Key Pressed: " << e.mKey << endl;
}

/*
 * Main function - uses boost to parse program arguments if not OSX
 */

int main (int argc, const char * argv[]) {
  
// We dont bother parsing in the case of OSX due to bundling
#ifndef _OPENGLCOURSE_OSX
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "OpenGLCourse Basic Application - No Options")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
#endif
  
    BasicApp b;

    // Launch our isntance of GLFW, sending the major and minor numbers

    GLFWApp a(b, 800, 600, false, argc, argv, "01_Context", 3, 2);

    return EXIT_SUCCESS;

}