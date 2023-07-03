#pragma once

#include<vector>
#include <iostream>

#include <../includes/tabulate/table.hpp>

using namespace tabulate;
using Row_t = Table::Row_t;

void displayMainMenu();
void displayCustomerMaintenanceMenu();

void displayTable(std::vector<std::string> header, std::vector<std::vector<std::string>> rows);
void displayHeader(std::string header);

int promptInt(std::string prompt);
std::string promptString(std::string prompt);
char promptChar(std::string prompt);