#ifndef __SHOW_TASK_HPP__
#define __SHOW_TASK_HPP__


class ShowTask {

private:
vector<Task> taskList;

public:
ShowTask();
ShowTask(vector<Task> tl) { taskList = tl; }

void display();
};


#endif
