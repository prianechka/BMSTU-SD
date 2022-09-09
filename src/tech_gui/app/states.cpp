#include "states.h"

AppState::AppState() {
    this->appState = NOT_AUTH;
}

STATES AppState::getState() {
    return this->appState;
}

void AppState::toStudentAuth() {
    if (this->appState == NOT_AUTH)
    {
        this->appState = STUDENT_AUTH;
    }
}

void AppState::toCommendAuth() {
    if (this->appState == NOT_AUTH)
    {
        this->appState = COMMEND_AUTH;
    }
}

void AppState::toSupplyAuth() {
    if (this->appState == NOT_AUTH)
    {
        this->appState = SUPPLY_AUTH;
    }
}

void AppState::toUnAuth() {
    if (!(this->appState == NOT_AUTH))
    {
        this->appState = NOT_AUTH;
    }
}

bool AppState::isCommendAuth() {
    return this->appState == COMMEND_AUTH;
}

bool AppState::isStudentAuth() {
    return this->appState == STUDENT_AUTH;
}

bool AppState::isSupplyAuth() {
    return this->appState == SUPPLY_AUTH;
}

bool AppState::isUnAuth() {
    return this->appState == NOT_AUTH;
}
