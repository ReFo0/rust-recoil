#include "common.hpp"

namespace Utils {
	void Error(const std::string& s) {
		printf("[ERROR] %s\n", s.c_str());
		throw std::runtime_error(s);
	}

	bool EndsWith(const std::string& haystack, const std::string& needle) {
		if (haystack.length() >= needle.length())
			return (!haystack.compare(haystack.length() - needle.length(), needle.length(), needle));

		return false;
	}

	std::vector<std::string> GetFilesInDirectory(const char* directory) {
		std::vector<std::string> files;
		std::filesystem::path path = directory;

		if (!std::filesystem::is_directory(path))
			return files;

		for (const auto& entry : std::filesystem::directory_iterator(directory))
			if (entry.is_regular_file())
				files.push_back(entry.path().string());
		return files;
	}

	std::vector<std::string> SplitString(std::string str, const char* delimiter) {
		std::vector<std::string> tokens;
		const auto delLen = strlen(delimiter);
		size_t pos = 0;
		while ((pos = str.find(delimiter)) != std::string::npos) {
			tokens.push_back(str.substr(0, pos));
			str.erase(0, pos + delLen);
		}
		tokens.push_back(str);

		return tokens;
	}
}