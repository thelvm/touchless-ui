//
// Created by lucas on 15/06/19.
//

#ifndef TOUCHLESS_UI_EDITKEYFRAME_HPP
#define TOUCHLESS_UI_EDITKEYFRAME_HPP

#include <gtkmm.h>

#include "gesture_parser.hpp"


class EditKeyframeHandsParserListener : public gesture_parser::HandsParserListener
{
public:
    void onConnect() override;

    void onDisconnect() override;
};

extern gesture_parser::HandsParser *handsParser;
extern EditKeyframeHandsParserListener *editKeyframeHandsParserListener;

extern Gtk::Window *editKeyframeWindow;

extern Gtk::Label *statusLabel;
extern Gtk::Button *getGestureButton;
extern Gtk::Label *countdownLabel;

extern Gtk::CheckButton *leftHandPresentCheckButton;
extern Gtk::CheckButton *leftThumbExtended;
extern Gtk::CheckButton *leftIndexExtended;
extern Gtk::CheckButton *leftMiddleExtended;
extern Gtk::CheckButton *leftRingExtended;
extern Gtk::CheckButton *leftPinkyExtended;

extern Gtk::SpinButton *leftRoll;
extern Gtk::SpinButton *leftPitch;
extern Gtk::SpinButton *leftYaw;

extern Gtk::CheckButton *rightHanPresentCheckButton;
extern Gtk::CheckButton *rightThumbExtended;
extern Gtk::CheckButton *rightIndexExtended;
extern Gtk::CheckButton *rightMiddleExtended;
extern Gtk::CheckButton *rightRingExtended;
extern Gtk::CheckButton *rightPinkyExtended;

extern Gtk::SpinButton *rightRoll;
extern Gtk::SpinButton *rightPitch;
extern Gtk::SpinButton *rightYaw;

extern Gtk::Button *keyframeCancelButton;
extern Gtk::Button *keyframeSaveButton;

void configEditKeyframe(const Glib::RefPtr<Gtk::Builder> &t_builder);

static void startGetGestureCountdown();

void getHandsFromLeap();

void handsToUI(gesture_parser::Hands *t_parsedHands);

void leftHandPresentToggle();

void rightHandPresentToggle();

void cancelButtonPressed();

void saveButtonPressed();

void openBlankKeyframeEditor();

#endif //TOUCHLESS_UI_EDITKEYFRAME_HPP
