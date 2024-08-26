/*!
    \file
    \brief ������������ ���� ���������� ��������� ������
*/


#ifndef COMMAND_LINE_UNIT_H
#define COMMAND_LINE_UNIT_H
                                    /// \breif ������������ ������� ������ ���������
enum MODES {
    SOLVE,                          ///<����� ������� ����������� ��������� � ������ ������������� �� �������
    TEST,                           ///<����� ������������ ������ ����������� ���������
    HELP                            ///<����� ��������� ��� ������� ������� ������
};

                                    /// \breif ��������� ��� ������ � ��������� ����������� ��������� ������
struct Cmd_arg {

    MODES mode;                     ///<����� ������
    const char *short_name;         ///<�������� ������� ������
    const char *full_name;          ///<������ ������� ������
    const char *discription;        ///<�������� ������

};

void check_args(int argc_cp, char** argv_cp, MODES* mode);

void change_mode(MODES* mode, MODES cur_md);

int help(void);

#endif //COMMAND_LINE_UNIT_H
