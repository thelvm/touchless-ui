//
// Created by lucas on 15/06/19.
//

#include "EditKeyframe.hpp"


gesture_parser::HandsParser *handsParser = nullptr;
EditKeyframeHandsParserListener *editKeyframeHandsParserListener = nullptr;

Gtk::Window *editKeyframeWindow = nullptr;

Gtk::Label *statusLabel = nullptr;
Gtk::Button *getGestureButton = nullptr;
Gtk::Label *countdownLabel = nullptr;

Gtk::CheckButton *leftHandPresentCheckButton = nullptr;
Gtk::CheckButton *leftThumbExtended = nullptr;
Gtk::CheckButton *leftIndexExtended = nullptr;
Gtk::CheckButton *leftMiddleExtended = nullptr;
Gtk::CheckButton *leftRingExtended = nullptr;
Gtk::CheckButton *leftPinkyExtended = nullptr;

Gtk::SpinButton *leftRoll = nullptr;
Gtk::SpinButton *leftPitch = nullptr;
Gtk::SpinButton *leftYaw = nullptr;

Gtk::CheckButton *rightHanPresentCheckButton = nullptr;
Gtk::CheckButton *rightThumbExtended = nullptr;
Gtk::CheckButton *rightIndexExtended = nullptr;
Gtk::CheckButton *rightMiddleExtended = nullptr;
Gtk::CheckButton *rightRingExtended = nullptr;
Gtk::CheckButton *rightPinkyExtended = nullptr;

Gtk::SpinButton *rightRoll = nullptr;
Gtk::SpinButton *rightPitch = nullptr;
Gtk::SpinButton *rightYaw = nullptr;

Gtk::Button *keyframeCancelButton = nullptr;
Gtk::Button *keyframeSaveButton = nullptr;

void configEditKeyframe(const Glib::RefPtr<Gtk::Builder> &t_builder)
{
    t_builder->get_widget("edit_keyframe_window", editKeyframeWindow);

    t_builder->get_widget("status_label", statusLabel);
    t_builder->get_widget("get_keyframe_button", getGestureButton);
    getGestureButton->signal_clicked().connect(sigc::ptr_fun(startGetGestureCountdown));
    t_builder->get_widget("countdown_label", countdownLabel);

    t_builder->get_widget("left_hand_present", leftHandPresentCheckButton);
    leftHandPresentCheckButton->signal_toggled().connect(sigc::ptr_fun(leftHandPresentToggle));

    t_builder->get_widget("left_thumb_extended", leftThumbExtended);
    t_builder->get_widget("left_index_extended", leftIndexExtended);
    t_builder->get_widget("left_middle_extended", leftMiddleExtended);
    t_builder->get_widget("left_ring_extended", leftRingExtended);
    t_builder->get_widget("left_pinky_extended", leftPinkyExtended);

    t_builder->get_widget("roll_l", leftRoll);
    t_builder->get_widget("pitch_l", leftPitch);
    t_builder->get_widget("yaw_l", leftYaw);

    t_builder->get_widget("right_hand_present", rightHanPresentCheckButton);
    rightHanPresentCheckButton->signal_toggled().connect(sigc::ptr_fun(rightHandPresentToggle));

    t_builder->get_widget("right_thumb_extended", rightThumbExtended);
    t_builder->get_widget("right_index_extended", rightIndexExtended);
    t_builder->get_widget("right_middle_extended", rightMiddleExtended);
    t_builder->get_widget("right_ring_extended", rightRingExtended);
    t_builder->get_widget("right_pinky_extended", rightPinkyExtended);

    t_builder->get_widget("roll_r", rightRoll);
    t_builder->get_widget("pitch_r", rightPitch);
    t_builder->get_widget("yaw_r", rightYaw);

    t_builder->get_widget("keyframe_cancel_button", keyframeCancelButton);
    keyframeCancelButton->signal_clicked().connect(sigc::ptr_fun(cancelButtonPressed));
    t_builder->get_widget("save_keyframe_button", keyframeSaveButton);
    keyframeSaveButton->signal_clicked().connect(sigc::ptr_fun(saveButtonPressed));

    handsParser = new gesture_parser::HandsParser();
    editKeyframeHandsParserListener = new EditKeyframeHandsParserListener();
    handsParser->setListener(editKeyframeHandsParserListener);
}

void startGetGestureCountdown()
{
    Glib::signal_timeout().connect_seconds_once(sigc::ptr_fun(getHandsFromLeap), 2);
}

void getHandsFromLeap()
{
    handsToUI(handsParser->getHands());
}

void handsToUI(gesture_parser::Hands *t_parsedHands)
{
    if (t_parsedHands != nullptr)
    {
        if (t_parsedHands->rightHand != nullptr)
        {
            rightHanPresentCheckButton->set_active(true);

            rightThumbExtended->set_active(t_parsedHands->rightHand->isThumbExtended());
            rightIndexExtended->set_active(t_parsedHands->rightHand->isIndexExtended());
            rightMiddleExtended->set_active(t_parsedHands->rightHand->isMiddleExtended());
            rightRingExtended->set_active(t_parsedHands->rightHand->isRingExtended());
            rightPinkyExtended->set_active(t_parsedHands->rightHand->isPinkyExtended());

            rightRoll->set_value(t_parsedHands->rightHand->getRollDegree());
            rightRoll->update();
            rightPitch->set_value(t_parsedHands->rightHand->getPitchDegree());
            rightPitch->update();
            rightYaw->set_value(t_parsedHands->rightHand->getYawDegree());
            rightYaw->update();
        } else
        {
            rightHanPresentCheckButton->set_active(false);
        }

        if (t_parsedHands->leftHand != nullptr)
        {
            leftHandPresentCheckButton->set_active(true);

            leftThumbExtended->set_active(t_parsedHands->leftHand->isThumbExtended());
            leftIndexExtended->set_active(t_parsedHands->leftHand->isIndexExtended());
            leftMiddleExtended->set_active(t_parsedHands->leftHand->isMiddleExtended());
            leftRingExtended->set_active(t_parsedHands->leftHand->isRingExtended());
            leftPinkyExtended->set_active(t_parsedHands->leftHand->isPinkyExtended());

            leftRoll->set_value(t_parsedHands->leftHand->getRollDegree());
            leftRoll->update();
            leftPitch->set_value(t_parsedHands->leftHand->getPitchDegree());
            leftPitch->update();
            leftYaw->set_value(t_parsedHands->leftHand->getYawDegree());
            leftYaw->update();
        } else
        {
            leftHandPresentCheckButton->set_active(false);
        }
    } else
    {
        rightHanPresentCheckButton->set_active(false);
        leftHandPresentCheckButton->set_active(false);
    }
}

void leftHandPresentToggle()
{
    leftThumbExtended->set_sensitive(leftHandPresentCheckButton->get_active());
    leftIndexExtended->set_sensitive(leftHandPresentCheckButton->get_active());
    leftMiddleExtended->set_sensitive(leftHandPresentCheckButton->get_active());
    leftRingExtended->set_sensitive(leftHandPresentCheckButton->get_active());
    leftPinkyExtended->set_sensitive(leftHandPresentCheckButton->get_active());

    leftRoll->set_sensitive(leftHandPresentCheckButton->get_active());
    leftPitch->set_sensitive(leftHandPresentCheckButton->get_active());
    leftYaw->set_sensitive(leftHandPresentCheckButton->get_active());
}

void rightHandPresentToggle()
{
    rightThumbExtended->set_sensitive(rightHanPresentCheckButton->get_active());
    rightIndexExtended->set_sensitive(rightHanPresentCheckButton->get_active());
    rightMiddleExtended->set_sensitive(rightHanPresentCheckButton->get_active());
    rightRingExtended->set_sensitive(rightHanPresentCheckButton->get_active());
    rightPinkyExtended->set_sensitive(rightHanPresentCheckButton->get_active());

    rightRoll->set_sensitive(rightHanPresentCheckButton->get_active());
    rightPitch->set_sensitive(rightHanPresentCheckButton->get_active());
    rightYaw->set_sensitive(rightHanPresentCheckButton->get_active());
}

void cancelButtonPressed()
{
    editKeyframeWindow->set_visible(false);
}

void saveButtonPressed()
{
    editKeyframeWindow->set_visible(false);
    // TODO Save gesture
}

void EditKeyframeHandsParserListener::onConnect()
{
    statusLabel->set_label("Connected!");
    getGestureButton->set_sensitive(true);
}

void EditKeyframeHandsParserListener::onDisconnect()
{
    statusLabel->set_label("Not connected.");
    getGestureButton->set_sensitive(false);
}

void openBlankKeyframeEditor() {
    if (!editKeyframeWindow->get_visible()) {
        handsToUI(new gesture_parser::Hands());
        editKeyframeWindow->set_visible(true);
        leftHandPresentToggle();
        rightHandPresentToggle();
    } else {
        editKeyframeWindow->present();
    }
}