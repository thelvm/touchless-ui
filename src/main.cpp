#include <gtkmm.h>
#include <iostream>
#include <giomm.h>
#include <thread>
#include <EditGestureWindow.hpp>

#include "EditKeyframe.hpp"

int main(int argc, char **argv) {
    auto touchless_ui_app = Gtk::Application::create(argc, argv, "com.thelvm.touchless.ui");
    auto builder = Gtk::Builder::create();
    try {
        builder->add_from_file("/home/lucas/Documents/software_project/Code/ui/xml/main.glade");
    }
    catch (const Glib::FileError &ex) {
        std::cerr << "FileError: " << ex.what() << std::endl;
        return 1;
    }
    catch (const Glib::MarkupError &ex) {
        std::cerr << "MarkupError: " << ex.what() << std::endl;
        return 1;
    }
    catch (const Gtk::BuilderError &ex) {
        std::cerr << "BuilderError: " << ex.what() << std::endl;
        return 1;
    }

    configEditGesture(builder);
    configEditKeyframe(builder);
    editKeyframeWindow->set_visible(false);

    touchless_ui_app->run(*editGestureWindow);


    return 0;
}