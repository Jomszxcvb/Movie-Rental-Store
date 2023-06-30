#include "StoreHelper.h"

void displayMainMenu() {
	Table table;
	table.format()
		.font_align(FontAlign::center)
		.border_color(Color::cyan);

	table.add_row(Row_t{ "WELCOME TO OUR MOVIE RENTAL STORE!" });
	table[0].format()
		.font_style({ FontStyle::bold })
		.font_color({ Color::yellow })
		.font_align(FontAlign::center);

	table.add_row(Row_t{ "Please select one of the following options:" });
	table[1].format()
		.font_align(FontAlign::center)
		.font_style({ FontStyle::italic })
		.font_color(Color::yellow);

	Table choices;
	choices.add_row(Row_t{ "1", "New Video" });
	choices.add_row(Row_t{ "2", "Rent a Video" });
	choices.add_row(Row_t{ "3", "Return a Video" });
	choices.add_row(Row_t{ "4", "Show Video Details" });
	choices.add_row(Row_t{ "5", "Display All Videos" });
	choices.add_row(Row_t{ "6", "Check Video Availability" });
	choices.add_row(Row_t{ "7", "Customer Maintenance" });
	choices.add_row(Row_t{ "8", "Exit Program" });
	choices.column(0).format()
		.font_align(FontAlign::center);
	choices.column(1).format()
		.font_align(FontAlign::left);

	table.add_row(Row_t{ choices });
	table[2].format()
		.font_color(Color::white);

	std::cout << table << "\n";
}

void displayCustomerMaintenanceMenu() {
	Table table;
	table.format()
		.font_align(FontAlign::center)
		.border_color(Color::cyan);

	table.add_row(Row_t{ "WELCOME TO OUR MOVIE RENTAL STORE!" });
	table[0].format()
		.font_style({ FontStyle::bold })
		.font_color({ Color::yellow })
		.font_align(FontAlign::center);

	table.add_row(Row_t{ "Please select one of the following options:" });
	table[1].format()
		.font_align(FontAlign::center)
		.font_style({ FontStyle::italic })
		.font_color(Color::yellow);

	Table choices;
	choices.add_row(Row_t{ "1", "Add New Customer" });
	choices.add_row(Row_t{ "2", "Show Customer Details" });
	choices.add_row(Row_t{ "3", " Return a Video" });
	choices.column(0).format()
		.font_align(FontAlign::center);
	choices.column(1).format()
		.font_align(FontAlign::left);

	table.add_row(Row_t{ choices });
	table[2].format()
		.font_color(Color::white);

	std::cout << table << "\n";
}

void displayTable(std::vector<std::string> headers, std::vector<std::vector<std::string>> rows) {
	Row_t tHeaders;
	for (auto& header : headers) {
		tHeaders.push_back(header);
	}

	Row_t tRows;
	for (auto& row : rows) {
		for (auto& column : row) {
			tRows.push_back(column);
		}
	}

	Table table;
	table.add_row(tHeaders);
	table.add_row(tRows);
	std::cout << table << "\n";
}

int promptInt(std::string prompt) {
	try {
		int input;
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			throw std::runtime_error("Invalid input. Please try again.");
		}
		return input;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return promptInt(prompt);
	}
}

std::string promptString(std::string prompt) {
	try {
		std::string input;
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			throw std::runtime_error("Invalid input. Please try again.");
		}
		return input;
	}
	catch (std::runtime_error& e) {
		std::cout << e.what() << "\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return promptString(prompt);
	}
}