#ifndef QUESTLOG_H
#define QUESTLOG_H



#include "CommonIncludes.h"
#include "Utils.h"
#include"EventManager.h"

class MenuLog;

class QuestLog {
private:
    class Quest {
    public:
        std::string name;
        StatusID complete_status;
    };

    MenuLog *log;

    // inner vector is a chain of events per quest, outer vector is a
    // list of quests.
    std::vector<std::vector<EventComponent> >quest_sections;

    std::vector<size_t> active_quest_ids;
    std::vector<size_t> complete_quest_ids;
    std::vector<Quest> quests;

public:
    explicit QuestLog(MenuLog *_log);
    ~QuestLog();
    void loadAll();
    void load(const std::string& filename);
    void logic();
    void createQuestList();
    bool newQuestNotification;
};
#endif // QUESTLOG_H
