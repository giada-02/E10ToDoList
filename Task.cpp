//
// Created by Giada on 16/01/2024.
//

#include "Task.h"

Task::Task(const std::string &d, bool done) : description(d), done(done) {}

void saveTasksToFile(const std::vector<Task> &tasks, const std::string &fileName) {
    std::ofstream ostream(fileName);
    ostream << tasks.size();
    for (const auto &task: tasks) {
        ostream << '\n' << task.getDescription() << " " << task.isDone();
    }
}

std::vector<Task> loadTasksFromFile(const std::string &fileName) {

    try {

        std::ifstream ifile;
        ifile.open(fileName);
        if (ifile.is_open()) {
            std::vector<Task> tasks;

            int n;
            ifile >> n; //number of tasks

            for (int i = 0; i < n; i++) {
                std::string description;
                bool done;

                ifile >> description >> done;
                tasks.push_back(Task(description, done));
            }
            ifile.close();
            return tasks;
        }

    } catch (const std::ifstream::failure &e){
        std::cerr << "File does not exist: " << e.what() << std::endl;
        return std::vector<Task>();
    }

}