//#include "raylib.h"
//#include <string>
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//class Resources {
//public:
//    int food = 1000;
//    int wood;
//    int stone;
//    int iron;
//
//    Resources() : food(0), wood(0), stone(0), iron(0) {}
//};
//struct Economy {
//    float gold;
//    float debt;         // when the gold gets less than zero
//    float taxRate;
//    float inflation;
//    float interestRate;
//    float corruption;
//
//    Economy() : gold(0.0f), debt(0.0f), taxRate(1.0f), inflation(0.0f), interestRate(0.05f), corruption(0.0f) {}
//};
//enum KingSkin {
//    DEFAULT,
//    SKIN1,
//    SKIN2
//};
//
//KingSkin kingSkin = DEFAULT;
//
//// this will devide the population into segments like peasents merchants and nobels
//struct SocialClass {
//    const char* name;
//    int population;
//    float unrest;
//
//    SocialClass() : name(""), population(0), unrest(0.0f) {}
//};
//
//class Population :public Resources {
//public:
//    int currentPopulation;
//    int employmentRate;
//
//    Population() {}
//    Population(int initialPopulation, int employmentRate, int wealth)
//        : currentPopulation(initialPopulation), employmentRate(employmentRate) {}
//
//    // replicating the effects of resources on population
//    void UpdatePopulation() {
//        if (food < 50) {
//            currentPopulation -= 5;
//        }
//        else if (employmentRate > 80) {
//            currentPopulation += 10;
//        }
//    }
//
//    void DisplayPopulation(int x, int y) {
//        string populationData = "Population: " + std::to_string(currentPopulation) +
//            "\nFood Supply: " + to_string(food) +
//            "\nEmployment Rate: " + to_string(employmentRate);
//
//        DrawText(populationData.c_str(), x, y, 20, WHITE);
//    }
//
//
//};
//
//class Military : public Resources {
//public:
//    int soldiers;
//    int morale;
//    float training; // percentage of training skills
//    int pay;
//    int swords;
//    int arrows;
//    int armours;
//    int corruption;
//    int costToTrain = 10;
//    int trainCoins;
//    string message;
//
//    Military() : message("") {}
//    Military(int soldiersCount, int morale, int pay, int corruption, int trainCoins, int training)
//        :training(training), trainCoins(trainCoins), soldiers(soldiersCount), morale(morale), pay(pay), corruption(corruption) {}
//
//    void displayinventory()
//    {
//        cout << soldiers << " Soldiers.\n";
//        cout << swords << " Swords.\n";
//        cout << arrows << " Arrows.\n";
//        cout << armours << " Armours.\n";
//
//    }
//
//    void Recruit(int population, int x, int y) {
//        // recruit 10 percent of the population on call
//        int newSoldiers = population / 10;
//        soldiers += newSoldiers;
//        message = "Recruited " + to_string(newSoldiers) + " soldiers!";
//        if (!message.empty()) {
//            DrawText(message.c_str(), x, y, 20, YELLOW);
//        }
//    }
//
//    void TrainSoldiers(int number, int x, int y) {
//        if (trainCoins > (number * costToTrain)) {
//            morale += 10;
//            training += 10;
//            pay += 10;
//            trainCoins -= (number * costToTrain);
//            message = "Training..Morale increased";
//        }
//        else {
//            message = "Not enough resources ";
//        }
//        if (!message.empty()) {
//            DrawText(message.c_str(), x, y, 20, RED);
//        }
//    }
//
//    void UpdateMilitary() {
//        if (food < 50) {
//            morale -= 10;
//        }
//
//        if (pay < 50) {
//            morale -= 15;
//        }
//
//        if (morale < 50) {
//            soldiers -= 5;
//        }
//
//        if (corruption > 50) {
//            morale -= 20;
//            std::cout << "Corruption is high, morale is decreasing" << endl;
//        }
//    }
//
//    void DisplayMilitary(int x, int y) {
//        std::string militaryData = "Soldiers: " + to_string(soldiers) +
//            "\nMorale: " + to_string(morale) + "%" +
//            "\nPay: " + to_string(pay) +
//            "\nCorruption: " + to_string(corruption) + "%";
//
//        DrawText(militaryData.c_str(), x, y, 20, WHITE);
//    }
//
//
//    void IncreaseCorruption() {
//        corruption += 5;  // Corruption increases over time
//    }
//};
//
//class Leadership {
//public:
//    string title;
//    int approvalRating;
//    bool isAlive;
//    int age;
//    string message;
//
//    // initialize X and Y with the best cordinates to dsiplay
//    int x;
//    int y;
//    Leadership() : isAlive(true), message("") {}
//    Leadership(int approvalRating) : approvalRating(approvalRating), isAlive(true), message("") {}
//
//    void UpdateLeadership(int change) {
//        approvalRating += change;
//        if (approvalRating < 0) approvalRating = 0;
//        if (approvalRating > 100) approvalRating = 100;
//        message = "the approval raiting is increased";
//        DrawText(message.c_str(), x, y, 20, WHITE);
//    }
//
//    void DisplayLeadership(int x, int y) {
//        string leadershipData = "Leadership Approval: " + to_string(approvalRating) + "%";
//        DrawText(leadershipData.c_str(), x, y, 20, WHITE);
//
//
//    }
//    // when the approval rating drop 
//
//    void Election() {
//        if (approvalRating < 30) {
//            message = "The leadership is weak. An election will take place!";
//            isAlive = false;
//        }
//        else {
//            message = "the leadership have the majority";
//        }
//        if (!message.empty()) {
//            DrawText(message.c_str(), x, y, 20, YELLOW);
//        }
//    }
//    // when the leader is not alive 
//    void militaryRaj() {
//        if (!isAlive) {
//            message = "military Raj has occurred";
//        }
//        else {
//            message = "No coupe";
//        }
//        DrawText(message.c_str(), x, y, 20, YELLOW);
//
//    }
//
//    void margya() {
//        if (isAlive && approvalRating < 10) {
//            message = "The leader has died in battle due to low morale";
//            isAlive = false;
//            DrawText(message.c_str(), x, y, 20, YELLOW);
//
//        }
//    }
//};
//
//struct Building {
//    string name;
//    Rectangle rect;  
//    Color color;
//
//};
//
//struct EventLog {
//    static const int MAX_EVENTS = 5;
//    char messages[MAX_EVENTS][128]; 
//    int count; 
//
//    EventLog() : count(0) {
//        for (int i = 0; i < MAX_EVENTS; ++i) {
//            messages[i][0] = '\0';
//        }
//    }
//
//    void add(const char* msg) {
//        if (count < MAX_EVENTS) {
//            strcpy_s(messages[count], sizeof(messages[count]), msg);
//            count++;
//        }
//        else {
//            for (int i = 1; i < MAX_EVENTS; ++i) {
//                strcpy_s(messages[i - 1], sizeof(messages[i - 1]), messages[i]);
//            }
//            strcpy_s(messages[MAX_EVENTS - 1], sizeof(messages[MAX_EVENTS - 1]), msg);
//        }
//    }
//};
//
//class Kingdom {
//public:
//    int day;            
//    SocialClass peasants;
//    SocialClass merchants;
//    SocialClass nobles;
//    Leadership leader;
//    Military army;
//    Economy economy;
//    Resources resources;
//    EventLog events;
//    Population total;
//
//    int warChance = 5;
//
//    Kingdom() {
//        day = 0;
//        peasants.name = "Peasants";
//        peasants.population = 100;  
//        peasants.unrest = 0.0f;
//        merchants.name = "Merchants";
//        merchants.population = 30;  
//        merchants.unrest = 0.0f;
//        nobles.name = "Nobles";
//        nobles.population = 10;     
//        nobles.unrest = 0.0f;
//        leader.title = "King";       
//        leader.age = 40;             
//        army.soldiers = 20;     
//        army.training = 50.0f;    
//        army.morale = 80.0f;       
//        army.corruption = 0.0f;    
//        economy.gold = 500.0f;       
//        economy.debt = 0.0f;
//        economy.taxRate = 1.0f;      
//        economy.inflation = 0.0f;
//        economy.interestRate = 0.05f;
//        economy.corruption = 0.1f;   
//        resources.food = 200;
//        resources.wood = 150;
//        resources.stone = 50;
//        resources.iron = 130;
//
//        total.currentPopulation = peasants.population + merchants.population + nobles.population + army.soldiers;
//    }
//
//    void addEvent(const char* msg) {
//        events.add(msg);
//    }
//
//    void updateday() {
//        day += 1; 
//
//        int p = peasants.population;
//        int foodProduced = (int)(p * 1.0f);
//        int woodProduced = (int)(p * 1.0f);
//        int stoneProduced = (int)(p * 1.0f);
//        int ironProduced = (int)(p * 1.0f);
//        //// Add a slight random variation to simulate seasons/harvest variability
//        //if (p > 0) {
//        //    // variation ±10%
//        //    foodProduced += (rand() % (foodProduced / 5 + 1)) - (foodProduced / 10);
//        //    woodProduced += (rand() % (woodProduced / 5 + 1)) - (woodProduced / 10);
//        //    stoneProduced += (rand() % (stoneProduced / 5 + 1)) - (stoneProduced / 10);
//        //    ironProduced += (rand() % (ironProduced / 5 + 1)) - (ironProduced / 10);
//        //    // ensure not negative
//        //    if (foodProduced < 0) foodProduced = 0;
//        //    if (woodProduced < 0) woodProduced = 0;
//        //    if (stoneProduced < 0) stoneProduced = 0;
//        //    if (ironProduced < 0) ironProduced = 0;
//        //}
//        // Update resources with production
//        resources.food += foodProduced;
//        resources.wood += woodProduced;
//        resources.stone += stoneProduced;
//        resources.iron += ironProduced;
//
//        int totalPopulation = peasants.population + merchants.population + nobles.population;
//        int foodNeeded = totalPopulation;         
//        foodNeeded += army.soldiers;               
//        if (resources.food < foodNeeded) {
//            int deficit = foodNeeded - resources.food;
//            int deaths = deficit;
//            int p_deaths = deaths;
//            if (p_deaths > peasants.population) p_deaths = peasants.population;
//            peasants.population -= p_deaths;
//            deaths -= p_deaths;
//            if (deaths > 0) {
//                int m_deaths = deaths;
//                if (m_deaths > merchants.population) m_deaths = merchants.population;
//                merchants.population -= m_deaths;
//                deaths -= m_deaths;
//            }
//            if (deaths > 0) {
//                int n_deaths = deaths;
//                if (n_deaths > nobles.population) n_deaths = nobles.population;
//                nobles.population -= n_deaths;
//                deaths -= n_deaths;
//            }
//            resources.food = 0;
//            peasants.unrest += 20.0f;
//            if (peasants.unrest > 100.0f) peasants.unrest = 100.0f;
//            merchants.unrest += 10.0f;
//            if (merchants.unrest > 100.0f) merchants.unrest = 100.0f;
//            nobles.unrest += 5.0f;
//            if (nobles.unrest > 100.0f) nobles.unrest = 100.0f;
//            addEvent("Famine: Severe food shortage! People are starving.");
//        }
//        else {
//            resources.food -= foodNeeded;
//        }
//
//        int woodNeeded = (int)(totalPopulation * 0.1f); 
//        if (resources.wood < woodNeeded) {
//            resources.wood = 0;
//            peasants.unrest += 5.0f; 
//            merchants.unrest += 3.0f;
//            nobles.unrest += 1.0f;
//            if (peasants.unrest > 100.0f) peasants.unrest = 100.0f;
//            if (merchants.unrest > 100.0f) merchants.unrest = 100.0f;
//            if (nobles.unrest > 100.0f) nobles.unrest = 100.0f;
//            addEvent("Hardship: Wood supplies exhausted. People lack firewood!");
//        }
//        else {
//            resources.wood -= woodNeeded;
//        }
//
//        if (army.soldiers > 0) {
//            int ironNeeded = (int)(army.soldiers * 0.1f); 
//            if (resources.iron < ironNeeded) {
//                army.morale -= 5.0f;
//                if (army.morale < 0.0f) army.morale = 0.0f;
//                resources.iron = 0;
//                addEvent("Shortage: Iron is scarce, army equipment is suffering.");
//            }
//            else {
//                resources.iron -= ironNeeded;
//            }
//        }
//
//        
//        float baseTax = peasants.population * 1.0f + merchants.population * 3.0f + nobles.population * 0.0f;
//        float grossTaxIncome = baseTax * economy.taxRate;
//        float netTaxIncome = grossTaxIncome * (1.0f - economy.corruption);
//        economy.gold += netTaxIncome;
//        float economySize = (float)totalPopulation + resources.food * 0.5f; 
//        if (economy.gold > economySize * 5.0f) {
//            economy.inflation += 0.02f;
//            if (economy.inflation > 1.0f) economy.inflation = 1.0f; 
//        }
//        float salaryCost = army.soldiers * 1.0f;  
//        if (economy.gold < salaryCost) {
//            float shortfall = salaryCost - economy.gold;
//            economy.gold = 0.0f;
//            float moraleDrop = (shortfall / salaryCost) * 20.0f;
//            army.morale -= moraleDrop;
//            if (army.morale < 0.0f) army.morale = 0.0f;
//            army.corruption += 0.05f;
//            if (army.corruption > 1.0f) army.corruption = 1.0f;
//            addEvent("Financial: Unable to pay all soldiers' wages. Morale falls.");
//        }
//        else {
//            economy.gold -= salaryCost;
//            army.morale += 1.0f;
//            if (army.morale > 100.0f) army.morale = 100.0f;
//        }
//
//        army.training += 2.0f; 
//        if (army.training > 100.0f) army.training = 100.0f;
//        if (army.morale > 50.0f) {
//            army.morale -= 0.5f;
//            if (army.morale < 50.0f) army.morale = 50.0f;
//        }
//        else if (army.morale < 50.0f) {
//            army.morale += 0.5f;
//            if (army.morale > 50.0f) army.morale = 50.0f;
//        }
//
//        float birthRate = 0.02f;  
//        float deathRate = 0.01f;   
//        int peasantsBirths = (int)(peasants.population * birthRate);
//        int merchantsBirths = (int)(merchants.population * birthRate);
//        int noblesBirths = (int)(nobles.population * birthRate);
//        int peasantsDeaths = (int)(peasants.population * deathRate);
//        int merchantsDeaths = (int)(merchants.population * deathRate);
//        int noblesDeaths = (int)(nobles.population * deathRate);
//        peasants.population += peasantsBirths - peasantsDeaths;
//        merchants.population += merchantsBirths - merchantsDeaths;
//        nobles.population += noblesBirths - noblesDeaths;
//        if (peasants.population < 0) peasants.population = 0;
//        if (merchants.population < 0) merchants.population = 0;
//        if (nobles.population < 0) nobles.population = 0;
//        totalPopulation = peasants.population + merchants.population + nobles.population;
//
//        leader.age += 1;
//        if (leader.age > 60) {
//            int deathRoll = rand() % 100;
//            if (deathRoll < (leader.age - 60)) {
//                char deathMsg[128];
//                sprintf_s(deathMsg, "%s has died of old age at %d.", leader.title, leader.age);
//                addEvent(deathMsg);
//
//            }
//        }
//
//      
//        int rand100 = rand() % 100;
//        int rand100b = rand() % 100;
//        bool eventOccurred = false;
//
//        if (army.soldiers > peasants.population / 2) {
//            warChance += 5;
//        }
//        if (!eventOccurred && rand100 < warChance) {
//            eventOccurred = true;
//            bool victory = (army.training > 70 && army.morale > 50 && army.soldiers > 10) && (rand() % 100 < 50);
//            int initialSoldiers = army.soldiers;
//            int soldierLoss = victory ? (army.soldiers * 10 / 100) : (army.soldiers * 30 / 100); 
//            if (soldierLoss < 1 && army.soldiers > 0) soldierLoss = 1; 
//            army.soldiers -= soldierLoss;
//            if (army.soldiers < 0) army.soldiers = 0;
//            int peasantLoss = victory ? (peasants.population * 2 / 100) : (peasants.population * 5 / 100);
//            peasants.population -= peasantLoss;
//            if (peasants.population < 0) peasants.population = 0;
//            int foodUse = 20; 
//            if (resources.food < foodUse) foodUse = resources.food;
//            resources.food -= foodUse;
//            int woodUse = 15;
//            if (resources.wood < woodUse) woodUse = resources.wood;
//            resources.wood -= woodUse;
//            int stoneUse = 10;
//            if (resources.stone < stoneUse) stoneUse = resources.stone;
//            resources.stone -= stoneUse;
//            int ironUse = 10;
//            if (resources.iron < ironUse) ironUse = resources.iron;
//            resources.iron -= ironUse;
//            float warCost = 50.0f;
//            if (economy.gold < warCost) {
//                economy.debt += (warCost - economy.gold);
//                economy.gold = 0.0f;
//            }
//            else {
//                economy.gold -= warCost;
//            }
//            if (victory) {
//                army.morale += 5.0f;
//                if (army.morale > 100.0f) army.morale = 100.0f;
//            }
//            else {
//                army.morale -= 10.0f;
//                if (army.morale < 0.0f) army.morale = 0.0f;
//            }
//            economy.inflation += 0.01f;
//            if (economy.inflation > 1.0f) economy.inflation = 1.0f;
//            peasants.unrest += 5.0f;
//            if (peasants.unrest > 100.0f) peasants.unrest = 100.0f;
//            merchants.unrest += 3.0f; 
//            if (merchants.unrest > 100.0f) merchants.unrest = 100.0f;
//            char warMsg[128];
//            if (victory) {
//                sprintf_s(warMsg, sizeof(warMsg), "War: Victory! We lost %d of %d soldiers.", soldierLoss, initialSoldiers);
//            }
//            else {
//                sprintf_s(warMsg, sizeof(warMsg), "War: Defeat... We lost %d of %d soldiers.", soldierLoss, initialSoldiers);
//            }
//
//            addEvent(warMsg);
//        }
//// event happening on the baisis of stats
//        int plagueChance = 3;
//        if (events.count > 0 && strstr(events.messages[events.count - 1], "Famine") != NULL) {
//            plagueChance += 5;
//        }
//        if (!eventOccurred && rand100b < plagueChance) {
//            eventOccurred = true;
//            int p_loss = peasants.population * 15 / 100;  
//            int m_loss = merchants.population * 10 / 100;
//            int n_loss = nobles.population * 5 / 100;      
//            peasants.population -= p_loss;
//            merchants.population -= m_loss;
//            nobles.population -= n_loss;
//            if (peasants.population < 0) peasants.population = 0;
//            if (merchants.population < 0) merchants.population = 0;
//            if (nobles.population < 0) nobles.population = 0;
//            int s_loss = army.soldiers * 10 / 100;
//            army.soldiers -= s_loss;
//            if (army.soldiers < 0) army.soldiers = 0;
//            peasants.unrest -= 5.0f;
//            if (peasants.unrest < 0.0f) peasants.unrest = 0.0f;
//            addEvent("Plague: A deadly plague spreads, killing many across all classes.");
//        }
//
//        if (!eventOccurred && peasants.unrest > 90.0f) {
//            eventOccurred = true;
//            int revoltLoss = peasants.population * 10 / 100;  // 10% peasants die in the revolt
//            int nobleLoss = nobles.population * 10 / 100;     // perhaps 10% nobles killed if revolt targets them
//            peasants.population -= revoltLoss;
//            nobles.population -= nobleLoss;
//            if (peasants.population < 0) peasants.population = 0;
//            if (nobles.population < 0) nobles.population = 0;
//            if (army.morale < 30.0f) {
//                addEvent("Revolt: Peasants rise up! The king has been overthrown in the uprising.");
//                leader.title = "Rebel Leader";
//                leader.age = 30;
//                economy.taxRate = 0.8f;
//                peasants.unrest = 20.0f;
//                nobles.unrest = 80.0f;
//            }
//            else {
//                addEvent("Revolt: Peasant uprising is crushed by the army.");
//                peasants.unrest = 50.0f;
//                army.morale -= 5.0f;
//                if (army.morale < 0.0f) army.morale = 0.0f;
//            }
//        }
//
//        if (!eventOccurred && army.morale < 5.0f && army.soldiers > 0) {
//            eventOccurred = true;
//            addEvent("Coup: The disloyal army has overthrown the government!");
//            leader.title = "General";
//            leader.age = 40;
//            int nobleLoss = nobles.population * 20 / 100;
//            nobles.population -= nobleLoss;
//            if (nobles.population < 0) nobles.population = 0;
//            nobles.unrest = 60.0f; 
//            peasants.unrest = 40.0f; 
//            merchants.unrest = 50.0f;
//            economy.taxRate = 1.0f;
//            army.morale = 50.0f;
//            army.corruption *= 0.5f;
//        }
//
//        if (!eventOccurred && economy.corruption > 0.5f) {
//            if ((rand() % 100) < 20) {
//                addEvent("Audit: Corruption scandal uncovered! Officials punished and funds recovered.");
//                float recovered = (peasants.population * 1.0f + merchants.population * 3.0f) * economy.taxRate * economy.corruption;
//                economy.gold += recovered;
//                economy.corruption -= 0.3f;
//                if (economy.corruption < 0.0f) economy.corruption = 0.0f;
//                peasants.unrest -= 5.0f; if (peasants.unrest < 0.0f) peasants.unrest = 0.0f;
//                merchants.unrest -= 5.0f; if (merchants.unrest < 0.0f) merchants.unrest = 0.0f;
//                nobles.unrest += 5.0f; if (nobles.unrest > 100.0f) nobles.unrest = 100.0f;
//            }
//        }
//        if (!eventOccurred && economy.corruption > 0.8f) {
//            addEvent("Betrayal: The Royal Treasurer absconds with a large portion of the treasury!");
//            economy.gold *= 0.5f;
//            economy.debt += 50.0f;
//            economy.corruption -= 0.5f;
//            if (economy.corruption < 0.0f) economy.corruption = 0.0f;
//        }
//
//        if (economy.debt > 500.0f) {
//            addEvent("Bankruptcy: The kingdom defaults on its loans, causing financial chaos!");
//            economy.debt *= 0.5f;
//            economy.inflation += 0.5f;
//            if (economy.inflation > 1.0f) economy.inflation = 1.0f;
//            peasants.unrest += 10.0f; if (peasants.unrest > 100.0f) peasants.unrest = 100.0f;
//            merchants.unrest += 15.0f; if (merchants.unrest > 100.0f) merchants.unrest = 100.0f;
//            nobles.unrest += 5.0f; if (nobles.unrest > 100.0f) nobles.unrest = 100.0f;
//        }
//
//        if (economy.gold < 0.0f) {
//            economy.debt += (-economy.gold);
//            economy.gold = 0.0f;
//        }
//        if (economy.corruption > 1.0f) economy.corruption = 1.0f;
//        if (peasants.unrest < 0.0f) peasants.unrest = 0.0f;
//        if (merchants.unrest < 0.0f) merchants.unrest = 0.0f;
//        if (nobles.unrest < 0.0f) nobles.unrest = 0.0f;
//        if (army.morale < 0.0f) army.morale = 0.0f;
//        if (army.morale > 100.0f) army.morale = 100.0f;
//        if (army.training > 100.0f) army.training = 100.0f;
//        if (army.corruption > 1.0f) army.corruption = 1.0f;
//    }
//};
//
//
//
//
//
//class RenderSystem {
//
//private:
//    Building buildings[10];
//    int buildingCount;
//    Rectangle chiefPosition;
//    float gridSize;
//    int screenWidth;
//    int screenHeight;
//    float nextEventTime = 10.0f; // Track time for random events
//    int x = screenWidth - 260; // side window position
//    int y;
//    string message;
//    int  currentLevel = 1;
//    Kingdom kingdom;
//
//
//    Population population;
//    Military military;
//    Leadership leadership;
//    // Military army;
//
//public:
//    void SelectKingSkin() {
//        bool skinMenuActive = true;
//
//        while (skinMenuActive && !WindowShouldClose()) {
//            BeginDrawing();
//            ClearBackground(BLACK);
//
//            Image character = LoadImage("kinga.PNG");
//            Texture2D tex = LoadTextureFromImage(character);
//            UnloadImage(character);
//            DrawTexture(tex, 430, 200, WHITE);
//
//            Image chara = LoadImage("kingccrop.PNG");
//            Texture2D texa = LoadTextureFromImage(chara);
//            UnloadImage(chara);
//            DrawTexture(texa, 30, 200, WHITE);
//
//            Image charaa = LoadImage("kingb.PNG");
//            Texture2D texaa = LoadTextureFromImage(charaa);
//            UnloadImage(charaa);
//            DrawTexture(texaa, 800, 200, WHITE);
//
//            Rectangle titleButtonRect = { 430, 10, 380, 60 };
//            float borderRadius = 20.0f;
//            DrawRectangleRounded(titleButtonRect, borderRadius, 0, GOLD);
//            DrawText("Select King Skin", 455, 25, 40, BLACK);
//
//            Rectangle optionABackground = { 80, 640, 200, 40 };
//            DrawRectangleRounded(optionABackground, borderRadius, 0, DARKGRAY);
//            DrawText("A. SON", 90, 650, 20, WHITE);
//
//            Rectangle optionBBackground = { 520, 640, 200, 40 };
//            DrawRectangleRounded(optionBBackground, borderRadius, 0, DARKGRAY);
//            DrawText("B. ELDER SON", 530, 650, 20, WHITE);
//
//            Rectangle optionCBackground = { 980, 640, 200, 40 };
//            DrawRectangleRounded(optionCBackground, borderRadius, 0, DARKGRAY);
//            DrawText("C. CHACHU", 1000, 650, 20, WHITE);
//
//            if (IsKeyPressed(KEY_A)) {
//                kingSkin = DEFAULT;
//                skinMenuActive = false;
//            }
//            else if (IsKeyPressed(KEY_B)) {
//                kingSkin = SKIN1;
//                skinMenuActive = false;
//            }
//            else if (IsKeyPressed(KEY_C)) {
//                kingSkin = SKIN2;
//                skinMenuActive = false;
//            }
//
//            if (IsKeyPressed(KEY_ESCAPE)) {
//                skinMenuActive = false;
//            }
//
//            EndDrawing();
//        }
//    }
//
//    void MainMenu() {
//        int menuOption = 0;
//        bool menuActive = true;
//
//        while (menuActive && !WindowShouldClose()) {
//            BeginDrawing();
//            ClearBackground(BLACK);
//
//            Image back = LoadImage("chachu1.JPG");
//            Texture2D tex = LoadTextureFromImage(back);
//            UnloadImage(back);
//            DrawTexture(tex, 0, 0, WHITE);
//
//            Rectangle startButtonRect = { 510, 590, 200, 50 };
//            float borderRadius = 20.0f;
//            DrawRectangleRounded(startButtonRect, borderRadius, 0, YELLOW);
//
//            DrawText("A. Start Game", 520, 600, 25, BLACK);
//
//            Rectangle quitButtonRect = { 510, 670, 200, 30 };
//            DrawRectangleRounded(quitButtonRect, borderRadius, 0, YELLOW);
//
//            DrawText("Press ESC to Quit", 520, 680, 20, BLACK);
//
//            if (IsKeyPressed(KEY_A)) {
//                menuOption = 1;
//                menuActive = false;
//            }
//
//            if (IsKeyPressed(KEY_ESCAPE)) {
//                CloseWindow();
//            }
//
//            EndDrawing();
//        }
//    }
//
//    // update cheif movement
//    void UpdateChiefMovement() {
//        if (IsKeyPressed(KEY_RIGHT) && chiefPosition.x + gridSize < screenWidth) chiefPosition.x += gridSize;
//        if (IsKeyPressed(KEY_LEFT) && chiefPosition.x > 0) chiefPosition.x -= gridSize;
//        if (IsKeyPressed(KEY_DOWN) && chiefPosition.y + gridSize < screenHeight) chiefPosition.y += gridSize;
//        if (IsKeyPressed(KEY_UP) && chiefPosition.y > 0) chiefPosition.y -= gridSize;
//    }
//
//
//    // building 0 menue display
//    void menueB0(int option) {
//        switch (option) {
//        case 1:
//            military.DisplayMilitary(920, 150);
//            break;
//        case 2:
//            population.DisplayPopulation(920, 175);
//            break;
//        case 3:
//            leadership.DisplayLeadership(920, 200);
//            break;
//        default:
//            break;
//        }
//    }
//
//
//    void DrawGrid() {
//        for (int x = 0; x < screenWidth; x += gridSize)
//            DrawLine(x, 0, x, screenHeight, LIGHTGRAY);
//        for (int y = 0; y < screenHeight; y += gridSize)
//            DrawLine(0, y, screenWidth, y, LIGHTGRAY);
//    }
//
//    // anything like title on the corner 
//    void Drawdiscription() const
//    {
//        string label = "LOONAYWALA";
//
//        int fontSize = 20;
//        int textW = MeasureText(label.c_str(), fontSize);
//        int textH = fontSize;
//
//        int padding = 8;
//        int boxX = 10;
//        int boxY = 10;
//        int boxW = textW + padding * 2;
//        int boxH = textH + padding * 2;
//
//        DrawRectangleRounded({ (float)boxX, (float)boxY,
//                               (float)boxW, (float)boxH }, 0.25f, 8, DARKBROWN);
//
//
//        int textX = boxX + padding;
//        int textY = boxY + padding;
//        DrawText(label.c_str(), textX, textY, fontSize, BEIGE);
//    }
//
//
//    // DRAW BULIDINGS
//    void DrawBuildings() {
//        int spacing = gridSize * 3;
//
//        for (int i = 0; i < buildingCount; i++) {
//            DrawRectangleRec({ buildings[i].rect.x + 5, buildings[i].rect.y + 5, gridSize, gridSize }, Fade(BLACK, 0.2f));
//
//            bool isNear = CheckCollisionRecs(chiefPosition, buildings[i].rect);
//            Color drawColor = isNear ? GOLD : buildings[i].color;
//
//            if (buildings[i].name == "Castle") {
//                DrawRectangleRec(buildings[i].rect, DARKGRAY);
//                DrawRectangle(buildings[i].rect.x - 10, buildings[i].rect.y - 40, gridSize / 4, gridSize / 3, DARKGRAY);
//                DrawRectangle(buildings[i].rect.x + gridSize - 10, buildings[i].rect.y - 40, gridSize / 4, gridSize / 3, DARKGRAY);
//                DrawRectangle(buildings[i].rect.x + gridSize / 4, buildings[i].rect.y + gridSize - 20, gridSize / 2, 20, BROWN);
//                DrawRectangle(buildings[i].rect.x + 15, buildings[i].rect.y + gridSize / 2, gridSize / 3, 15, LIGHTGRAY);
//                DrawRectangle(buildings[i].rect.x + gridSize / 2, buildings[i].rect.y + gridSize / 2, gridSize / 3, 15, LIGHTGRAY);
//            }
//
//            else if (buildings[i].name == "Barracks") {
//                DrawRectangleRec(buildings[i].rect, RED);
//                DrawRectangle(buildings[i].rect.x + 5, buildings[i].rect.y - 15, gridSize - 20, 15, RED);
//                DrawRectangle(buildings[i].rect.x + 15, buildings[i].rect.y - 30, 10, 15, DARKBROWN);
//                DrawRectangle(buildings[i].rect.x + 5, buildings[i].rect.y + 10, 30, 15, LIGHTGRAY);
//                DrawRectangle(buildings[i].rect.x + gridSize - 40, buildings[i].rect.y + 10, 30, 15, LIGHTGRAY);
//                DrawRectangle(buildings[i].rect.x + (gridSize / 2) - 20, buildings[i].rect.y + gridSize - 20, 40, 20, BROWN);
//            }
//
//            else if (buildings[i].name == "Market") {
//                DrawRectangleRec(buildings[i].rect, ORANGE);
//                DrawRectangle(buildings[i].rect.x + 10, buildings[i].rect.y - 20, gridSize - 20, 20, ORANGE);
//                DrawRectangle(buildings[i].rect.x + 15, buildings[i].rect.y + gridSize - 20, gridSize - 30, 20, YELLOW);
//                DrawRectangle(buildings[i].rect.x + 15, buildings[i].rect.y + gridSize / 2, gridSize / 3, 15, LIGHTGRAY);
//                DrawRectangle(buildings[i].rect.x + gridSize / 2, buildings[i].rect.y + gridSize / 2, gridSize / 3, 15, LIGHTGRAY);
//            }
//
//            else if (buildings[i].name == "Town Hall") {
//                DrawRectangleRec(buildings[i].rect, BLUE);
//                DrawRectangle(buildings[i].rect.x + gridSize / 3, buildings[i].rect.y - 30, gridSize / 3, 30, DARKBLUE);
//                DrawTriangle({ buildings[i].rect.x + gridSize / 3, buildings[i].rect.y - 30 },
//                    { buildings[i].rect.x + gridSize / 3 + gridSize / 6, buildings[i].rect.y - 60 },
//                    { buildings[i].rect.x + gridSize / 3 + gridSize / 3, buildings[i].rect.y - 30 }, DARKBLUE);
//                DrawRectangle(buildings[i].rect.x + 15, buildings[i].rect.y + gridSize / 2, gridSize / 3, 15, LIGHTGRAY);
//                DrawRectangle(buildings[i].rect.x + gridSize / 2, buildings[i].rect.y + gridSize / 2, gridSize / 3, 15, LIGHTGRAY);
//            }
//
//            else if (buildings[i].name == "Blacksmith") {
//                DrawRectangleRec(buildings[i].rect, BROWN);
//                DrawRectangle(buildings[i].rect.x + 10, buildings[i].rect.y - 15, gridSize - 20, 15, DARKBROWN);
//                DrawRectangle(buildings[i].rect.x + gridSize / 3, buildings[i].rect.y + gridSize - 30, gridSize / 3, 15, DARKGRAY);
//                DrawRectangle(buildings[i].rect.x + 20, buildings[i].rect.y - 30, 10, 15, DARKBROWN);
//                DrawRectangle(buildings[i].rect.x + (gridSize / 2) - 20, buildings[i].rect.y + gridSize - 20, 40, 20, BROWN);
//            }
//
//            else if (buildings[i].name == "Church") {
//                DrawRectangleRec(buildings[i].rect, PURPLE);
//                DrawRectangle(buildings[i].rect.x + 10, buildings[i].rect.y - 15, gridSize - 20, 15, DARKPURPLE);
//                DrawRectangle(buildings[i].rect.x + gridSize / 2 - 5, buildings[i].rect.y - 40, 10, 20, DARKPURPLE);
//                DrawTriangle({ buildings[i].rect.x + gridSize / 2 - 5, buildings[i].rect.y - 40 },
//                    { buildings[i].rect.x + gridSize / 2 + 5, buildings[i].rect.y - 60 },
//                    { buildings[i].rect.x + gridSize / 2 + 15, buildings[i].rect.y - 40 }, DARKPURPLE);
//                DrawLine(buildings[i].rect.x + gridSize / 2, buildings[i].rect.y - 60, buildings[i].rect.x + gridSize / 2, buildings[i].rect.y - 75, WHITE);
//                DrawLine(buildings[i].rect.x + gridSize / 2 - 10, buildings[i].rect.y - 67, buildings[i].rect.x + gridSize / 2 + 10, buildings[i].rect.y - 67, WHITE);
//            }
//
//            DrawText(buildings[i].name.c_str(), buildings[i].rect.x + 5, buildings[i].rect.y + 35, 10, WHITE);
//
//            if (isNear) {
//                DrawText(("Entered: " + buildings[i].name).c_str(), 10, 560, 18, MAROON);
//            }
//        }
//
//    }
//
//
//
//    static const Color SKIN;
//    static const Color CLOAK;
//    static const Color BELT;
//
//    // two characters of cheif
//    void DrawChief2()
//    {
//        float headR = gridSize * 0.18f;
//        float Heady = chiefPosition.y + 25;
//        float Headx = chiefPosition.x + 50;
//
//        DrawCircle(Headx, Heady, headR, SKIN);
//
//        float crownX = Headx - 25;
//        float crownY = chiefPosition.y + 5;
//
//        DrawRectangle(crownX, crownY, 50, 10, GOLD);
//
//        float spikeW = 10, spikeH = 12;
//        for (int i = 0; i < 3; ++i)
//        {
//            float sx = crownX + spikeW * (2 * i);
//            DrawTriangle({ sx, crownY },
//                { sx + spikeW, crownY },
//                { sx + spikeW * 0.5f, crownY - spikeH },
//                GOLD);
//        }
//
//        const Color BELT_CLR = GOLD;
//        const Color BOOT_CLR = DARKBROWN;
//
//        float bodyW = 40, bodyH = 50;
//        float bodyX = crownX + 5, bodyY = crownY + 35;
//        DrawRectangle(bodyX, bodyY, bodyW, bodyH, BLACK);
//
//        float beltH = bodyH * 0.14f;
//        DrawRectangle(bodyX, bodyY + bodyH * 0.45f, bodyW, beltH, BELT_CLR);
//
//        float armW = gridSize * 0.12f, armH = gridSize * 0.30f;
//        float armY = bodyY + bodyH * 0.15f;
//
//        DrawRectangle(bodyX - armW, armY, armW, armH, BLACK);
//        DrawRectangle(bodyX + bodyW, armY, armW, armH, BLACK);
//
//        float legW = gridSize * 0.12f, legH = gridSize * 0.28f;
//        float legY = bodyY + bodyH;
//
//        DrawRectangle(bodyX + bodyW * 0.15f, legY, legW, legH, BOOT_CLR);
//        DrawRectangle(bodyX + bodyW * 0.73f, legY, legW, legH, BOOT_CLR);
//
//        float swordHandleX = bodyX + bodyW + armW * 0.5f;
//        float swordHandleY = armY - gridSize * 0.04f;
//        float handleH = gridSize * 0.10f;
//        float bladeH = gridSize * 0.50f;
//        float bladeW = 4.0f;
//
//        DrawRectangle(swordHandleX - bladeW * 0.5f,
//            swordHandleY,
//            bladeW,
//            handleH,
//            BROWN);
//
//        DrawRectangle(swordHandleX - 10,
//            swordHandleY,
//            20,
//            3,
//            GOLD);
//
//        DrawRectangle(swordHandleX - bladeW * 0.5f,
//            swordHandleY - bladeH,
//            bladeW,
//            bladeH,
//            LIGHTGRAY);
//
//        DrawCircle(swordHandleX, swordHandleY + handleH, 3, GOLD);
//    }
//    void pixelCheif() {
//        if (kingSkin = DEFAULT) {
//            int chiefx = chiefPosition.x;
//            int chiefy = chiefPosition.y;
//            Image chiefimage = LoadImage("kingc2.PNG");
//            Texture2D chieftex = LoadTextureFromImage(chiefimage); // Convert image to texture
//            UnloadImage(chiefimage);  // We no longer need the image after converting it to a texture
//            DrawTexture(chieftex, chiefx, chiefy, WHITE);
//        }if (kingSkin = SKIN1) {
//            int chiefx = chiefPosition.x;
//            int chiefy = chiefPosition.y;
//            Image chiefimage = LoadImage("kingc2.PNG");
//            Texture2D chieftex = LoadTextureFromImage(chiefimage); // Convert image to texture
//            UnloadImage(chiefimage);  // We no longer need the image after converting it to a texture
//            DrawTexture(chieftex, chiefx, chiefy, WHITE);
//        }
//        if (kingSkin = SKIN2) {
//            int chiefx = chiefPosition.x;
//            int chiefy = chiefPosition.y;
//            Image chiefimage = LoadImage("kingc2.PNG");
//            Texture2D chieftex = LoadTextureFromImage(chiefimage); // Convert image to texture
//            UnloadImage(chiefimage);  // We no longer need the image after converting it to a texture
//            DrawTexture(chieftex, chiefx, chiefy, WHITE);
//        }
//    }
//
//
//
//
//    void DrawChief() {
//
//
//        float headR = gridSize * 0.18;
//        float Heady = chiefPosition.y + 25;
//        float Headx = chiefPosition.x + 50;
//
//        DrawCircle(Headx, Heady, headR, SKIN);
//
//        float crownX = Headx - 25;
//        float crownY = chiefPosition.y + 5;
//
//        DrawRectangle(crownX, crownY, 50, 10, GOLD);
//
//        float spikeW = 10;
//        float spikeH = 12;
//        for (int i = 0; i < 3; ++i)
//        {
//            // sx check 
//            float sx = crownX + spikeW * (2 * i);
//            DrawTriangle({ sx,crownY }, { sx + spikeW,crownY }, { sx + spikeW * 0.5f, crownY - spikeH }, GOLD);
//        }
//
//
//        float bodyW = 40;
//        float bodyH = 50;
//        float bodyX = crownX + 5;
//        float bodyY = crownY + 35;
//        DrawRectangle(bodyX, bodyY, bodyW, bodyH, RED);
//
//        float beltH = bodyH * 0.14;
//        DrawRectangle(bodyX, bodyY + bodyH * 0.45, bodyW, beltH, BELT);
//
//
//        float armW = gridSize * 0.12;
//        float armH = gridSize * 0.30;
//        float armY = bodyY + bodyH * 0.15;
//
//        DrawRectangle(bodyX - armW, armY, armW, armH, RED);
//        DrawRectangle(bodyX + bodyW, armY, armW, armH, RED);
//
//
//        float legW = gridSize * 0.12;
//        float legH = gridSize * 0.28;
//        float legY = bodyY + bodyH;
//
//        DrawRectangle(bodyX + bodyW * 0.15, legY, legW, legH, DARKBROWN);
//        DrawRectangle(bodyX + bodyW * 0.73, legY, legW, legH, DARKBROWN);
//
//
//        float sceptreX1 = bodyX + bodyW + armW * 0.5;
//        float sceptreY1 = armY - gridSize * 0.10;
//        float sceptreY2 = sceptreY1 + gridSize * 0.65;
//        DrawLineEx({ sceptreX1, sceptreY1 }, { sceptreX1, sceptreY2 }, 4, GOLD);
//        DrawCircle(sceptreX1, sceptreY1, 6, YELLOW);
//
//    }
//
//
//
//
//
//    void background() {
//        for (int y = 0; y < screenHeight; y++) {
//            DrawLine(0, y, screenWidth, y, GRAY);
//        }
//    }
//
//
//    RenderSystem() {}
//
//    // initialization of the builind dimensions / name / color 
//    // Chief starting position
//    // population military leadership initialization
//    void Init() {
//        screenWidth = 1200;
//        screenHeight = 700;
//        gridSize = 100; // size of each block
//        InitWindow(screenWidth, screenHeight, "Stronghold");
//        SetTargetFPS(60);
//
//        // Chief starting position
//        chiefPosition = { 1000,500 , (float)gridSize, (float)gridSize };
//
//        buildingCount = 7;
//        const int x = 10;
//        const int y = 4;
//
//        // initialization of the builind dimensions / name / color 
//        buildings[0] = { "Castle",
//
//            {(float)(x * gridSize - 50), // rect.x
//            (float)(y * gridSize - 100),  //rect.y
//            (float)gridSize,
//            (float)gridSize},
//            DARKGRAY };
//
//        buildings[1] = { "Barracks", {(float)((4) * gridSize), (float)((y - 1) * gridSize), (float)gridSize, (float)gridSize}, RED };
//        buildings[2] = { "Market", {(float)((650)), (float)((550)), (float)gridSize, (float)gridSize}, ORANGE };
//        //buildings[3] = { "Granary", {(float)((x - 1) * gridSize - 70), (float)((y + 1) * gridSize), (float)gridSize, (float)gridSize}, RED };
//        //buildings[4] = { "Town Hall", {(float)((x + 1) * gridSize + 70), (float)((y + 1) * gridSize), (float)gridSize, (float)gridSize}, BLUE };
//        buildings[5] = { "Blacksmith", {(float)(450), (float)((200)), (float)gridSize, (float)gridSize}, BROWN };
//        buildings[6] = { "Church", {(float)(750), (float)((250)), (float)gridSize, (float)gridSize}, PURPLE };
//
//
//
//        population = Population(500, 70, 100);
//        military = Military(200, 80, 100, 10, 1000, 50);
//        leadership = Leadership(75);
//
//        std::srand(std::time(nullptr));
//    }
//
//    // notice board window
//    void DrawSideWindow() {
//        int sideWindowWidth = 600;
//        int sideWindowHeight = screenHeight; //700
//        int sideWindowX = 0;
//        int sideWindowY = 0;
//
//        DrawRectangle(sideWindowX, sideWindowY, sideWindowWidth, sideWindowHeight, DARKGRAY);
//
//        DrawText("Notices", sideWindowX + 10, sideWindowY + 10, 20, WHITE);
//
//
//    }
//    void pixelbackground() {
//        int sideWindowX = 0;
//        int sideWindowY = 0;
//
//        int chiefx = 0;
//        int chiefy = 0;
//        Image chiefimage = LoadImage("village.JPG");
//        Texture2D chieftex = LoadTextureFromImage(chiefimage); // Convert image to texture
//        UnloadImage(chiefimage);  // We no longer need the image after converting it to a texture
//        DrawTexture(chieftex, chiefx, chiefy, WHITE);
//
//
//    }
//
//    void castlemenue()
//    {
//        //Drwa Castle Menu
//        DrawText("Castle Menu", 20, 530, 20, RED);
//        DrawText("1. Soldiers Salaries (1 gold → 1 soldier)", 20, 555, 20, BLACK);
//        DrawText("2. Diplometic Relations", 20, 580, 20, BLACK);
//        DrawText("3. King's Policies", 20, 605, 20, BLACK);
//        DrawText("Select an option (1-3):", 20, 655, 20, BLACK);
//
//        if (IsKeyPressed(KEY_ONE))
//        {
//            if (kingdom.economy.gold >= military.soldiers)
//            {
//                kingdom.economy.gold -= military.soldiers;
//                
//                cout << "   - Executed: Soldiers salaries have been paid.\n";
//            }
//            else
//            {
//                cout << "   - Not enough gold to pay salaries.\n";
//                military.soldiers -= military.soldiers - kingdom.economy.gold;
//                kingdom.peasants.population += military.soldiers - kingdom.economy.gold;
//                kingdom.economy.gold -= military.soldiers - kingdom.economy.gold;
//                military.morale -= 3;
//                kingdom.nobles.unrest -= 3;
//            }
//        }
//        else if (IsKeyPressed(KEY_TWO))
//        {
//
//            //Diplometic Relations
//
//            //int trade_wood = 10;
//            //if (kingdom.resources.wood >= trade_wood) {
//            //    int food_gained = 10;  // Balanced supply: 10 wood → 10 food
//            //    if (kingdom.resources.food < kingdom.resources.wood) {
//            //        food_gained = 20;  // Food is scarce, wood is plentiful: 10 wood trades for 20 food
//            //    }
//            //    else if (kingdom.resources.wood < kingdom.resources.food) {
//            //        food_gained = 5;   // Wood is scarce, food is abundant: 10 wood trades for 5 food
//            //    }
//            //    kingdom.resources.wood -= trade_wood;
//            //    kingdom.resources.food += food_gained;
//            //    cout << "   - Executed: Traded " << trade_wood << " wood for " << food_gained << " food.\n";
//            //}
//            //else {
//            //    cout << "   - Not enough wood to trade for food.\n";
//            //}
//        }
//        else if (IsKeyPressed(KEY_THREE))
//        {
//
//            //KING's Policies
//
//            //int trade_iron = 10;
//            //if (kingdom.resources.iron >= trade_iron) {
//            //    int gold_gained = 10;  // Balanced supply: 10 iron → 10 gold
//            //    if (kingdom.economy.gold < kingdom.resources.iron) {
//            //        gold_gained = 20;  // Gold is scarce, iron is plentiful: 10 iron trades for 20 gold
//            //    }
//            //    else if (kingdom.resources.iron < kingdom.economy.gold) {
//            //        gold_gained = 5;   // Iron is scarce, gold is abundant: 10 iron trades for 5 gold
//            //    }
//            //    kingdom.resources.iron -= trade_iron;
//            //    kingdom.economy.gold += gold_gained;
//            //    cout << "   - Executed: Traded " << trade_iron << " iron for " << gold_gained << " gold.\n";
//            //}
//            //else {
//            //    cout << "   - Not enough iron to trade for gold.\n";
//            //}
//        }
//        else if (IsKeyPressed(KEY_FOUR))
//        {
//            //EXIT CASTLE
//        }
//
//    }
//
//    void barrackmenue()
//    {
//        //Draw Barrack Menu
//        DrawText("Barrack Menu", 20, 530, 20, RED);
//        DrawText("1. Train Troops (10 gold → 10 soldiers)", 20, 555, 20, BLACK);
//        DrawText("2. Get Equipment (10 gold → 15 arrows)", 20, 580, 20, BLACK);
//        DrawText("3. Resruit Slodiers (10 gold → 10 soldiers)", 20, 605, 20, BLACK);
//        DrawText("4. Inventory Display ", 20, 605, 20, BLACK);
//        DrawText("5. Exit Barrack", 20, 655, 20, BLACK);
//        DrawText("Select an option (1-5):", 20, 680, 20, BLACK);
//
//        if (IsKeyPressed(KEY_ONE))
//        {
//            if (kingdom.economy.gold >= military.soldiers)
//            {
//                kingdom.economy.gold -= military.soldiers;
//                // kingdom.resources.food += 10;
//                cout << "   - Executed: Soldiers training successful.\n";
//            }
//            else
//            {
//                cout << "   - Not enough gold to train the soldiers.\n";
//                /* army.soldiers -= army.soldiers - kingdom.economy.gold;
//                 kingdom.peasants.population += army.soldiers - kingdom.economy.gold;
//                 kingdom.economy.gold -= army.soldiers - kingdom.economy.gold;*/
//                military.morale -= 5;
//                // kingdom.nobles.unrest -= 3;
//            }
//        }
//        else if (IsKeyPressed(KEY_TWO))
//        {
//            //BUY EQUIPMENT
//        }
//        else if (IsKeyPressed(KEY_THREE))
//        {
//
//            int recruits = 0;
//            if (kingdom.warChance > 50) {
//                recruits = kingdom.peasants.population / 5;
//                military.soldiers += recruits;
//                cout << "   - Executed: " << recruits << " soldiers added to Military.\n";
//            }
//            else {
//                cout << "   - Not enough population to recruit soldiers.\n";
//            }
//        }
//        else if (IsKeyPressed(KEY_FOUR))
//        {
//            military.displayinventory();
//        }
//        else if (IsKeyPressed(KEY_FIVE))
//        {
//            //EXIT BARRACK
//        }
//
//    }
//
//    void blacksmithmenue()
//    {
//        //Draw Blacksmith Menu
//        DrawText("Blacksmith Menu", 20, 530, 20, RED);
//        DrawText("1. Forge Swords (10 iron → 5 swords)", 20, 555, 20, BLACK);
//        DrawText("2. Forge Arrows (10 wood → 5 arrows)", 20, 580, 20, BLACK);
//        DrawText("3. Forge Armours (10 iron → 2 Armours)", 20, 605, 20, BLACK);
//        DrawText("4. Exit Blacksmith", 20, 630, 20, BLACK);
//        DrawText("Select an option (1-4):", 20, 655, 20, BLACK);
//
//        if (IsKeyPressed(KEY_ONE))
//        {
//            if (kingdom.resources.iron >= 10)
//            {
//                kingdom.resources.iron -= 10;
//                military.swords += 5;
//                cout << "   - Executed: Swords forged successfully.\n";
//            }
//            else
//            {
//                cout << "   - Not enough iron to forge Swords.\n";
//                /* military.soldiers -= military.soldiers - kingdom.economy.gold;
//                 kingdom.peasants.population += military.soldiers - kingdom.economy.gold;
//                 kingdom.economy.gold -= military.soldiers - kingdom.economy.gold;
//                 military.morale -= 3;
//                 kingdom.nobles.unrest -= 3;*/
//            }
//        }
//        else if (IsKeyPressed(KEY_TWO))
//        {
//            if (kingdom.resources.wood >= 10)
//            {
//                kingdom.resources.wood -= 10;
//                military.arrows += 5;
//                cout << "   - Executed: Arrows forged successfully.\n";
//            }
//            else
//            {
//                cout << "   - Not enough wood to forge Arrows.\n";
//                /* military.soldiers -= military.soldiers - kingdom.economy.gold;
//                 kingdom.peasants.population += military.soldiers - kingdom.economy.gold;
//                 kingdom.economy.gold -= military.soldiers - kingdom.economy.gold;
//                 military.morale -= 3;
//                 kingdom.nobles.unrest -= 3;*/
//            }
//        }
//        else if (IsKeyPressed(KEY_THREE))
//        {
//            if (kingdom.resources.iron >= 10)
//            {
//                kingdom.resources.iron -= 10;
//                military.armours = 2;
//                cout << "   - Executed: armour forged successfully.\n";
//            }
//            else
//            {
//                cout << "   - Not enough iron to forge armour.\n";
//                /* military.soldiers -= military.soldiers - kingdom.economy.gold;
//                 kingdom.peasants.population += military.soldiers - kingdom.economy.gold;
//                 kingdom.economy.gold -= military.soldiers - kingdom.economy.gold;
//                 military.morale -= 3;
//                 kingdom.nobles.unrest -= 3;*/
//            }
//        }
//        else if (IsKeyPressed(KEY_FOUR))
//        {
//            //EXIT BlackSmith
//        }
//
//    }
//
//    void churchmenue()
//    {
//        //Draw Church Menu
//        DrawText("Church Menu", 20, 530, 20, RED);
//        DrawText("1. Noble Meeting (unrest -= 5)", 20, 555, 20, BLACK);
//        DrawText("2. War negotiations (morale += 10)", 20, 580, 20, BLACK);
//        DrawText("3. Worship (unrest -= 2 && morale += 5)", 20, 605, 20, BLACK);
//        DrawText("4. Exit Church", 20, 630, 20, BLACK);
//        DrawText("Select an option (1-4):", 20, 655, 20, BLACK);
//
//        if (IsKeyPressed(KEY_ONE))
//        {
//            if (leadership.approvalRating < 50)
//            {
//                leadership.approvalRating += 10;
//                kingdom.nobles.unrest -= 10;
//                kingdom.peasants.unrest -= 10;
//                kingdom.merchants.unrest -= 10;
//            }
//            else
//            {
//                cout << "   - No need for Noble Meeting.\n";
//                /* military.soldiers -= military.soldiers - kingdom.economy.gold;
//                 kingdom.peasants.population += military.soldiers - kingdom.economy.gold;
//                 kingdom.economy.gold -= military.soldiers - kingdom.economy.gold;
//                 military.morale -= 3;
//                 kingdom.nobles.unrest -= 3;*/
//            }
//        }
//        else if (IsKeyPressed(KEY_TWO))
//        {
//            if (kingdom.warChance > 50)
//            {
//                cout << "War Negotiations under way!\n";
//                if (rand() % 4 == 4)
//                {
//                    cout << "Negotiations unsuccessful!\n";
//                    leadership.approvalRating -= 10;
//                    kingdom.nobles.unrest += 10;
//                    kingdom.peasants.unrest += 10;
//                    kingdom.merchants.unrest += 10;
//                }
//                else
//                {
//                    cout << "Negotiations successful!\n";
//                    leadership.approvalRating += 10;
//                    kingdom.nobles.unrest -= 10;
//                    kingdom.peasants.unrest -= 10;
//                    kingdom.merchants.unrest -= 10;
//                }
//            }
//            else
//            {
//                cout << "   - No War Negotiations in progress.\n";
//                /* military.soldiers -= military.soldiers - kingdom.economy.gold;
//                 kingdom.peasants.population += military.soldiers - kingdom.economy.gold;
//                 kingdom.economy.gold -= military.soldiers - kingdom.economy.gold;
//                 military.morale -= 3;
//                 kingdom.nobles.unrest -= 3;*/
//            }
//        }
//        else if (IsKeyPressed(KEY_THREE))
//        {
//            leadership.approvalRating += 2;
//            kingdom.nobles.unrest -= 3;
//            kingdom.peasants.unrest -= 3;
//            kingdom.merchants.unrest -= 3;
//            military.morale += 5;
//        }
//        else if (IsKeyPressed(KEY_FOUR))
//        {
//            //EXIT BlackSmith
//        }
//
//    }
//
//    void marketmenue() {
//        // Draw Market Menu
//        DrawText("Market Menu", 20, 530, 20, RED);
//        DrawText("1. Buy Food (10 gold → 10 food)", 20, 555, 20, BLACK);
//        DrawText("2. Trade Wood for Food (10 wood → ? food)", 20, 580, 20, BLACK);
//        DrawText("3. Trade Iron for Gold (10 iron → ? gold)", 20, 605, 20, BLACK);
//        DrawText("4. Exit Market", 20, 630, 20, BLACK);
//        DrawText("Select an option (1-4):", 20, 655, 20, BLACK);
//
//        if (IsKeyPressed(KEY_ONE)) {
//            if (kingdom.economy.gold >= 10) {
//                kingdom.economy.gold -= 10;
//                kingdom.resources.food += 10;
//                cout << "   - Executed: Bought 10 food for 10 gold.\n";
//            }
//            else {
//                cout << "   - Not enough gold to buy food.\n";
//            }
//        }
//        else if (IsKeyPressed(KEY_TWO)) {
//            int trade_wood = 10;
//            if (kingdom.resources.wood >= trade_wood) {
//                int food_gained = 10;  // Balanced supply: 10 wood → 10 food
//                if (kingdom.resources.food < kingdom.resources.wood) {
//                    food_gained = 20;  // Food is scarce, wood is plentiful: 10 wood trades for 20 food
//                }
//                else if (kingdom.resources.wood < kingdom.resources.food) {
//                    food_gained = 5;   // Wood is scarce, food is abundant: 10 wood trades for 5 food
//                }
//                kingdom.resources.wood -= trade_wood;
//                kingdom.resources.food += food_gained;
//                cout << "   - Executed: Traded " << trade_wood << " wood for " << food_gained << " food.\n";
//            }
//            else {
//                cout << "   - Not enough wood to trade for food.\n";
//            }
//        }
//        else if (IsKeyPressed(KEY_THREE)) {
//            int trade_iron = 10;
//            if (kingdom.resources.iron >= trade_iron) {
//                int gold_gained = 10;  // Balanced supply: 10 iron → 10 gold
//                if (kingdom.economy.gold < kingdom.resources.iron) {
//                    gold_gained = 20;  // Gold is scarce, iron is plentiful: 10 iron trades for 20 gold
//                }
//                else if (kingdom.resources.iron < kingdom.economy.gold) {
//                    gold_gained = 5;   // Iron is scarce, gold is abundant: 10 iron trades for 5 gold
//                }
//                kingdom.resources.iron -= trade_iron;
//                kingdom.economy.gold += gold_gained;
//                cout << "   - Executed: Traded " << trade_iron << " iron for " << gold_gained << " gold.\n";
//            }
//            else {
//                cout << "   - Not enough iron to trade for gold.\n";
//            }
//        }
//
//
//    }
//    // call functions and check the collision of building and the cheif
//    void  Run() {
//
//        int selectedOption = 0;
//        while (!WindowShouldClose()) {
//
//            if (IsKeyPressed(KEY_SPACE)) {
//                kingdom.updateday();
//            }
//            UpdateChiefMovement();
//
//
//
//
//            BeginDrawing();
//            ClearBackground(SKYBLUE);
//            background();
//            DrawGrid();
//            pixelbackground();
//            //DrawBuildings();
//            //DrawChief2();
//            pixelCheif();
//            Drawdiscription();
//            //DrawSideWindow();
//
//            ClearBackground(RAYWHITE);
//
//            // Prepare some colors for different texts
//            Color titleColor = GREEN;
//            Color statColor = GOLD;
//            Color warnColor = RED;
//            Color goodColor = DARKGREEN;
//            Color neutralColor = YELLOW;
//
//            DrawText(TextFormat("DAY:", kingdom.day), 1200, 10, 20, titleColor);
//            DrawText(TextFormat("DAY: ", kingdom.leader.title, kingdom.leader.age),
//                200, 10, 20, titleColor);
//
//            // Display Population of each class
//            DrawText("Population:", 10, 50, 18, titleColor);
//            DrawText(TextFormat("Peasants: %d", kingdom.peasants.population),
//                30, 70, 18, neutralColor);
//            DrawText(TextFormat("Merchants: %d", kingdom.merchants.population),
//                30, 90, 18, neutralColor);
//            DrawText(TextFormat("Nobles: %d", kingdom.nobles.population),
//                30, 110, 18, neutralColor);
//            // Unrest levels (if noteworthy)
//            DrawText(TextFormat("Unrest - Peasants: %.0f%%, Merchants: %.0f%%, Nobles: %.0f%%",
//                kingdom.peasants.unrest, kingdom.merchants.unrest, kingdom.nobles.unrest),
//                30, 130, 16, (kingdom.peasants.unrest > 50 || kingdom.merchants.unrest > 50 || kingdom.nobles.unrest > 50) ? warnColor : statColor);
//
//            // Display Resources
//            DrawText("Resources:", 10, 170, 18, titleColor);
//            DrawText(TextFormat("Food: %d", kingdom.resources.food), 30, 190, 18,
//                (kingdom.resources.food < (kingdom.peasants.population + kingdom.merchants.population + kingdom.nobles.population)) ? warnColor : neutralColor);
//            DrawText(TextFormat("Wood: %d", kingdom.resources.wood), 150, 190, 18,
//                (kingdom.resources.wood < (int)((kingdom.peasants.population + kingdom.merchants.population + kingdom.nobles.population) * 0.1f)) ? warnColor : neutralColor);
//            DrawText(TextFormat("Stone: %d", kingdom.resources.stone), 270, 190, 18, neutralColor);
//            DrawText(TextFormat("Iron: %d", kingdom.resources.iron), 390, 190, 18,
//                (kingdom.resources.iron < kingdom.army.soldiers * 1) ? warnColor : neutralColor);
//
//            // Display Economy
//            DrawText("Economy:", 10, 230, 18, titleColor);
//            DrawText(TextFormat("Gold: %.1f", kingdom.economy.gold), 30, 250, 18,
//                (kingdom.economy.gold < 20.0f) ? warnColor : neutralColor);
//            DrawText(TextFormat("Debt: %.1f", kingdom.economy.debt), 150, 250, 18,
//                (kingdom.economy.debt > 0.0f) ? warnColor : neutralColor);
//            DrawText(TextFormat("Tax Rate: %.0f%%", kingdom.economy.taxRate * 100), 30, 270, 18, neutralColor);
//            DrawText(TextFormat("Inflation: %.0f%%", kingdom.economy.inflation * 100), 200, 270, 18,
//                (kingdom.economy.inflation > 0.3f) ? warnColor : neutralColor);
//            DrawText(TextFormat("Corruption: %.0f%%", kingdom.economy.corruption * 100), 370, 270, 18,
//                (kingdom.economy.corruption > 0.5f) ? warnColor : neutralColor);
//
//            // Display Military
//            DrawText("Military:", 10, 310, 18, titleColor);
//            DrawText(TextFormat("Soldiers: %d", kingdom.army.soldiers), 30, 330, 18,
//                (kingdom.army.soldiers == 0) ? warnColor : neutralColor);
//            DrawText(TextFormat("Training: %.0f%%", kingdom.army.training), 150, 330, 18,
//                (kingdom.army.training < 30.0f) ? warnColor : neutralColor);
//            DrawText(TextFormat("Morale: %.0f%%", kingdom.army.morale), 300, 330, 18,
//                (kingdom.army.morale < 30.0f) ? warnColor : neutralColor);
//            DrawText(TextFormat("Army Corruption: %.0f%%", kingdom.army.corruption * 100),
//                30, 350, 18, (kingdom.army.corruption > 0.3f) ? warnColor : neutralColor);
//
//            // Display recent Event Log
//            DrawText("Recent Events:", 10, 390, 18, titleColor);
//            int evCount = kingdom.events.count;
//            for (int i = 0; i < evCount; ++i) {
//                // print each event message, the oldest at i=0 to newest at i=evCount-1
//                DrawText(kingdom.events.messages[i], 30, 410 + 20 * i, 16, statColor);
//            }
//            if (evCount == 0) {
//                DrawText("No significant events yet.", 30, 410, 16, statColor);
//            }
//
//            // Draw instruction
//            DrawText("Press SPACE to advance turn", 500, 670, 20, BLACK);
//
//
//            if (CheckCollisionRecs(chiefPosition, buildings[0].rect)) {
//
//                castlemenue();
//
//            }
//
//            if (CheckCollisionRecs(chiefPosition, buildings[1].rect)) {
//
//                barrackmenue();
//            }
//            if (CheckCollisionRecs(chiefPosition, buildings[5].rect)) {
//
//                blacksmithmenue();
//
//            }
//            if (CheckCollisionRecs(chiefPosition, buildings[6].rect)) {
//                churchmenue();     
//            }
//
//            if (CheckCollisionRecs(chiefPosition, buildings[2].rect)) {
//
//                marketmenue();
//            }
//
//            EndDrawing();
//        }
//        CloseWindow();
//    }
//};
//
//
//const Color RenderSystem::SKIN = { 255, 224, 189, 255 };
//const Color RenderSystem::CLOAK = { 128,  32,  96, 255 };
//const Color RenderSystem::BELT = { 60,  30,   0, 255 };
//
//int main()
//{
//    RenderSystem renderer;
//    renderer.Init();
//    renderer.MainMenu();
//    renderer.SelectKingSkin();
//    renderer.Run();
//    return 0;
//}