# Kingdom Simulation Game

## Overview
This is a kingdom simulation game that allows you to manage a kingdom, including resources, population, military, economy, and leadership. The game is built using the `raylib` library for graphics and interactive elements. Players control the kingdom’s growth, manage resources, train and recruit soldiers, implement leadership policies, and handle events that occur over time.

## Features
- **Resource Management**: Manage food, wood, stone, and iron to support the population and military.
- **Military System**: Recruit, train, and maintain soldiers, with morale and equipment.
- **Leadership System**: Change leadership styles, implement policies, and handle transitions of power.
- **Population Control**: Track and update the population based on available resources and employment rates.
- **Event Log**: Keep track of important events like resource shortages, military victories/defeats, and leadership changes.
- **Building Menus**: Interact with various buildings like barracks, market, blacksmith, and church to manage the kingdom's operations.
- **Day-Night Cycle**: The game progresses day-by-day with events happening each day based on the kingdom's status.

## Requirements
- `raylib` - A simple and easy-to-use library for game development.
- C++ Compiler (e.g., GCC, MSVC)
- CMake (for building the project)


Game Controls
Arrow Keys: Move the chief around the map.

Spacebar: Advance to the next day.

Building Menus: Interact with buildings like the castle, barracks, and market to manage the kingdom.

Castle: Manage military, leadership, and policies.

Barracks: Recruit and train soldiers.

Market: Trade resources.

Blacksmith: Forge weapons and armor.

Church: Manage noble unrest and war negotiations.

Game Mechanics
Resources: Food, wood, stone, and iron are required for the population and military. Resources are gathered daily and traded when necessary.

Military: Soldiers are recruited from the population and trained to improve their morale. Soldiers are necessary for defending the kingdom and engaging in wars.

Economy: Gold is used to pay soldiers, buy resources, and forge equipment. Taxes are collected from the population.

Leadership: The kingdom's leader can have different leadership styles, including Authoritarian, Democratic, and Economic. The leader's decisions affect the kingdom’s policies, economy, and social unrest.

Events: Random events occur during the game, such as famine, wars, and leadership transitions.
