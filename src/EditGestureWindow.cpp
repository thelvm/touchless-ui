//
// Created by lucas on 17/06/19.
//

#include "EditGestureWindow.hpp"
#include "EditKeyframe.hpp"

Gtk::Window *editGestureWindow = nullptr;
Gtk::ListBox *gestureKeyframesListBox = nullptr;
Gtk::Button *addKeyframeButton = nullptr;
Gtk::Button *removeKeyframeButton = nullptr;
Gtk::Button *editKeyframeButton = nullptr;

void configEditGesture(const Glib::RefPtr<Gtk::Builder> &t_builder) {
    t_builder->get_widget("edit_gesture_window", editGestureWindow);
    t_builder->get_widget("add_keyframe_button", addKeyframeButton);
    addKeyframeButton->signal_clicked().connect(sigc::ptr_fun(addKeyframe));
    t_builder->get_widget("remove_keyframe_button", removeKeyframeButton);
    t_builder->get_widget("edit_keyframe_button", editKeyframeButton);
    t_builder->get_widget("keyframe_list", gestureKeyframesListBox);


    //addKeyframeButton->signal_clicked().connect(sigc::ptr_fun(openBlankKeyframeEditor));
}



void addKeyframe() {
    auto *newKeyframe = new Gtk::Label();
    newKeyframe->set_label("Keyframe");
    newKeyframe->set_visible(true);
    gestureKeyframesListBox->add(*newKeyframe);
}

