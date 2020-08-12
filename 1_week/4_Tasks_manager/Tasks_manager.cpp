#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <tuple>
#include <map>




enum class TaskStatus
{
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};


using TasksInfo = std::map<TaskStatus, int>;


class TeamTasks
{
public:
	std::tuple<TasksInfo, TasksInfo> PerformPersonsTasks(const std::string& person, int task_count);
	const TasksInfo& GetPersonTasksInfo(const std::string& person) const;
	void AddNewTask(const std::string& person);



private:
	std::map<std::string, TasksInfo> team;
};


std::tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonsTasks(const std::string& person, int task_count)
{
	TasksInfo to_update;
	TasksInfo updated;
	TasksInfo untouched;

	auto& person_tasks = team.at(person);
	for (auto& item : person_tasks)
	{
		if (item.first == TaskStatus::NEW)
		{
			if (item.second > 0)
			{
				int current_new_tasks = item.second;
				while (current_new_tasks > 0 && task_count > 0)
				{
					updated[TaskStatus::IN_PROGRESS]++;
					to_update[TaskStatus::IN_PROGRESS]++;

					current_new_tasks--;
					task_count--;
				}

				if (current_new_tasks > 0)
				{
					untouched[TaskStatus::NEW] += current_new_tasks;
					to_update[TaskStatus::NEW] += current_new_tasks;
				}
			}
		}


		if (item.first == TaskStatus::IN_PROGRESS)
		{
			if (item.second > 0)
			{
				int current_in_progress_tasks = item.second;
				while (current_in_progress_tasks > 0 && task_count > 0)
				{
					updated[TaskStatus::TESTING]++;
					to_update[TaskStatus::TESTING]++;

					current_in_progress_tasks--;
					task_count--;
				}

				if (current_in_progress_tasks > 0)
				{
					untouched[TaskStatus::IN_PROGRESS] += current_in_progress_tasks;
					to_update[TaskStatus::IN_PROGRESS] += current_in_progress_tasks;
				}
			}
		}


		if (item.first == TaskStatus::TESTING)
		{
			if (item.second > 0)
			{
				int current_testing_tasks = item.second;
				while (current_testing_tasks > 0 && task_count > 0)
				{
					updated[TaskStatus::DONE]++;
					to_update[TaskStatus::DONE]++;

					current_testing_tasks--;
					task_count--;
				}

				if (current_testing_tasks > 0)
				{
					untouched[TaskStatus::TESTING] += current_testing_tasks;
					to_update[TaskStatus::TESTING] += current_testing_tasks;
				}
			}
		}


		if (item.first == TaskStatus::DONE)
		{
			if (item.second > 0)
			{
				to_update[TaskStatus::DONE] += item.second;
			}
		}
	}


	team[person] = to_update;

	return std::make_tuple(updated, untouched);
}


const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person) const
{
	return team.at(person);
}


void TeamTasks::AddNewTask(const std::string& person)
{
	team[person][TaskStatus::NEW]++;
}











void PrintTasks(const std::string& person, TasksInfo& tasks_info);


int main()
{
	TeamTasks t;

	t.AddNewTask("Ivan");
	t.AddNewTask("Ivan");
	t.AddNewTask("Ivan");
	t.AddNewTask("Ivan");
	t.AddNewTask("Ivan");
	t.AddNewTask("Ivan");
	t.AddNewTask("Ivan");

	TasksInfo ivan_tasks = t.GetPersonTasksInfo("Ivan");
	PrintTasks("Ivan", ivan_tasks);

	std::tuple<TasksInfo,TasksInfo> res =  t.PerformPersonsTasks("Ivan", 4);

	ivan_tasks = t.GetPersonTasksInfo("Ivan");
	PrintTasks("Ivan", ivan_tasks);

	return 0;
}


void PrintTasks(const std::string& person, TasksInfo& tasks_info)
{
	std::cout << person + "'s tasks:\n";
	std::cout << std::left << std::setw(13) << "NEW:"         << tasks_info[TaskStatus::NEW]         << std::endl;
	std::cout << std::left << std::setw(13) << "IN_PROGRESS:" << tasks_info[TaskStatus::IN_PROGRESS] << std::endl;
	std::cout << std::left << std::setw(13) << "TESTING:"     << tasks_info[TaskStatus::TESTING]     << std::endl;
	std::cout << std::left << std::setw(13) << "DONE:"        << tasks_info[TaskStatus::DONE]        << std::endl;
}
