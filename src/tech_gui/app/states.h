#ifndef STATES_H
#define STATES_H

enum STATES {
    NOT_AUTH,
    STUDENT_AUTH,
    SUPPLY_AUTH,
    COMMEND_AUTH
};

class AppState
{
public:
    AppState();
    ~AppState() = default;
    STATES getState();
    void toStudentAuth();
    void toSupplyAuth();
    void toCommendAuth();
    void toUnAuth();
    bool isUnAuth();
    bool isStudentAuth();
    bool isSupplyAuth();
    bool isCommendAuth();
private:
    STATES appState;
};

#endif // STATES_H
