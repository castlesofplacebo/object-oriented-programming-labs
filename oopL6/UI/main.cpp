#include <iostream>
#include "../DAL/ReportRepository.h"
#include "../DAL/StaffRepository.h"
#include "../DAL/TaskRepository.h"
#include "../BLL/Service.h"
#include "ViewModels/TaskVM.h"
#include "ViewModels/LeaderVM.h"
#include "ViewModels/WorkerVM.h"
#include "../DAL/StaffRepository.h"
#include "Controller.h"

int main() {
    try {
        StaffRepository s;
        Service current(&s,
                        new TaskRepository,
                        new ReportRepository);

        TaskVM task("wanna sleep", "zzzzzzzzzz");
        TaskVM task1("wanna sleep again", "but should finish it");

        Controller c(&current);

        date _creationDate{10, 10, 2020};

        unsigned int id1 = c.addTask(&task, _creationDate);
        unsigned int id2 = c.addTask(&task1, _creationDate);

        LeaderVM teamLead("Ivan Ivanov");
        WorkerVM worker("Petr Petrov");
        WorkerVM worker1("Semen Semyonov");
        WorkerVM worker2("Alexandr Alexandrov");

        unsigned int sId1 = c.addTeamleader(&teamLead);
        unsigned int sId2 = c.addWorker(&worker);

        //c.setHeadToStaff(&teamLead, &worker);
        s.getItem(1)->addEmployees(s.getItem(2));

        //хочу чтобы что-нибудь выводилось а оно не выводится :(
        std::cout << s.getItem(2)->getHierarchy();


        c.changeTaskStatus(&task, Active, _creationDate);

        c.addCommentToTask(&task, "comment1", _creationDate);

    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}