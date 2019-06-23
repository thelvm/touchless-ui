//
// Created by lucas on 17/06/19.
//

#ifndef TOUCHLESS_UI_EDITGESTUREWINDOW_HPP
#define TOUCHLESS_UI_EDITGESTUREWINDOW_HPP

#include <gtkmm.h>

extern Gtk::Window *editGestureWindow;
extern Gtk::ListBox *gestureKeyframesListBox;
extern Gtk::Button *addKeyframeButton;
extern Gtk::Button *removeKeyframeButton;
extern Gtk::Button *editKeyframeButton;

void configEditGesture(const Glib::RefPtr<Gtk::Builder> &t_builder);

void openBlankKeyframeEditor();

void addKeyframe();

#endif //TOUCHLESS_UI_EDITGESTUREWINDOW_HPP
