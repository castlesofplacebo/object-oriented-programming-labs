#include <iostream>
#include "../DAL/ReportRepository.h"
#include "../DAL/StaffRepository.h"
#include "../DAL/TaskRepository.h"
#include "../BLL/Service.h"
#include "ViewModels/TaskVM.h"
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

        StaffVM teamLead("Ivan Ivanov");
        StaffVM worker("Petr Petrov");
        StaffVM worker1("Semen Semyonov");
        StaffVM worker2("Alexandr Alexandrov");

        unsigned int sId1 = c.addStaff(&teamLead);
        unsigned int sId2 = c.addStaff(&worker);
        unsigned int sId3 = c.addStaff(&worker1);
        unsigned int sId4 = c.addStaff(&worker2);

        c.setHeadToStaff(&teamLead, &worker);
        c.setHeadToStaff(&teamLead, &worker1);
        c.setHeadToStaff(&worker1, &worker2);

        c.setStaffToTask(&task, sId2, _creationDate);
        c.setStaffToTask(&task1, sId4, _creationDate);

        std::vector<TaskVM> answer = c.getEmployeesTasks(&teamLead);
        for (auto i : answer) {
            //std::cout << i.getName() << " " << i.getDescription();
        }

        c.changeTaskStatus(&task, Active, _creationDate);

        c.addCommentToTask(&task, "comment1", _creationDate);


    }
    catch (std::exception &err) {
        std::cout << err.what() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}