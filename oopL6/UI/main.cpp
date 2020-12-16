#include <iostream>
#include "../DAL/ReportRepository.h"
#include "../DAL/StaffRepository.h"
#include "../DAL/TaskRepository.h"
#include "../BLL/Service.h"
#include "ViewModels/TaskVM.h"
#include "ViewModels/LeaderVM.h"
#include "ViewModels/WorkerVM.h"
#include "Controller.h"

int main() {
    try {
        Service current(new StaffRepository,
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
        unsigned int sId3 = c.addWorker(&worker1);
        unsigned int sId4 = c.addWorker(&worker2);
        c.setHeadToStaff(&teamLead, &worker);
        c.setHeadToStaff(&teamLead, &worker1);
        c.setHeadToStaff(&worker, &worker2);

        c.setStaffToTask(&task, sId4, _creationDate);

        c.changeTaskStatus(&task, Active, _creationDate);
        c.addCommentToTask(&task, "comment1", _creationDate);

        c.createDailyReport(&worker2, _creationDate, "comment to daily report");
        date _date{12, 10, 2020};
        c.createDailyReport(&worker2, _date, "comment to daily report");
        c.createSprintReport(&worker2, "finish sprint");

        c.createSprintReport(&teamLead, "ok");

    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}