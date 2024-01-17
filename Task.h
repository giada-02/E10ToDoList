//
// Created by Giada on 16/01/2024.
//

#ifndef E10TODOLIST_TASK_H
#define E10TODOLIST_TASK_H

#include <string>
#include <vector>
#include <fstream>

class Task {
public:
    explicit Task(const std::string &d, bool done = false);

    //getters
    const std::string &getDescription() const {
        return description;
    }

    bool isDone() const {
        return done;
    }

private:
    std::string description;
    bool done;
};

void saveTasksToFile(const std::vector<Task> &tasks, const std::string &fileName);

std::vector<Task> loadTasksFromFile(const std::string &fileName);

#endif //E10TODOLIST_TASK_H
