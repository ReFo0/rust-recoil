#pragma once
#include <direct.h>
#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "../config/common.hpp"

namespace Config {
	template <typename T>
	using DeserializeFn = std::function<T(const char*)>;
	using SerializeFn = std::function<std::string(void*)>;

	const char* g_file = "C://script//settings.ini";


	enum class Type {
		INT,
		FLOAT,
		STRING,
		BOOL,
		IMVEC2,
		IMVEC4

	};

	struct Item {
		std::string m_name;
		std::string m_category;
		Type m_type;
		void* m_pObj;

		Item(const char* name, const char* category, const Type& type, void* pObj) {
			this->m_name = name;
			this->m_category = category;
			this->m_type = type;
			this->m_pObj = pObj;
		}
	};

	std::vector<Item> g_items;

	template <typename T>
	T& Add(const char* name, const char* category, const Type& type, const T& defaultValue = {}) {
		T* pT = new T(defaultValue);
		Item item(name, category, type, (void*)pT);
		g_items.push_back(item);
		return *pT;
	}

	// numerics
	SerializeFn IntToString = [](void* pObj) -> std::string {
		return std::to_string(*((int*)pObj));
	};

	DeserializeFn<int> StringToInt = [](const char* str) -> int {
		return std::atoi(str);
	};

	SerializeFn FloatToString = [](void* pObj) -> std::string {
		return std::to_string(*((float*)pObj));
	};

	DeserializeFn<float> StringToFloat = [](const char* str) -> float {
		auto val = std::stof(str);
		return val;
	};

	// bool
	SerializeFn BoolToString = [](void* pObj) -> std::string {
		auto b = *(bool*)pObj;
		return b ? "true" : "false";
	};

	DeserializeFn<bool> StringToBool = [](const char* str) -> bool {
		return !strcmp(str, "true");
	};

	// ImVec2
	SerializeFn ImVec2ToString = [](void* pObj) -> std::string {
		auto vec = *((ImVec2*)pObj);
		return std::to_string(vec.x) + "," + std::to_string(vec.y);
	};


	SerializeFn ImVec4ToString = [](void* pObj) -> std::string {
		auto vec = *((ImVec4*)pObj);
		return std::to_string(vec.x) + "," + std::to_string(vec.y) + "," + std::to_string(vec.z) + "," + std::to_string(vec.w);
	};

	DeserializeFn<ImVec2> StringToImVec2 = [](const char* str) -> ImVec2 {
		ImVec2 vec(0, 0);
		auto tokens = Utils::SplitString(str, ",");

		if (tokens.size() == 2) {
			vec.x = std::stof(tokens[0]);
			vec.y = std::stof(tokens[1]);
		}

		return vec;
	};


	DeserializeFn<ImVec4> StringToImVec4 = [](const char* str) -> ImVec4 {
		ImVec4 vec(0, 0, 0, 0);
		auto tokens = Utils::SplitString(str, ",");

		if (tokens.size() == 4) {
			vec.x = std::stof(tokens[0]);
			vec.y = std::stof(tokens[1]);
			vec.z = std::stof(tokens[2]);
			vec.w = std::stof(tokens[3]);
		}

		return vec;
	};
	std::string Serialize(const Item& item) {
		const auto type = item.m_type;

		switch (type) {
		case Type::INT:
			return IntToString(item.m_pObj);
		case Type::FLOAT:
			return FloatToString(item.m_pObj);
		case Type::STRING:
			return *((std::string*)item.m_pObj);
		case Type::BOOL:
			return BoolToString(item.m_pObj);
		case Type::IMVEC2:
			return ImVec2ToString(item.m_pObj);
		case Type::IMVEC4:
			return ImVec4ToString(item.m_pObj);
		};

		return "<default_null>";
	}

	void Deserialize(Item& item, std::string strValue) {
		const auto type = item.m_type;

		switch (type) {
		case Type::INT:
			*(int*)item.m_pObj = StringToInt(strValue.c_str());
			break;
		case Type::FLOAT:
			*(float*)item.m_pObj = StringToFloat(strValue.c_str());
			break;
		case Type::STRING:
			*(std::string*)item.m_pObj = strValue;
			break;
		case Type::BOOL:
			*(bool*)item.m_pObj = StringToBool(strValue.c_str());
			break;
		case Type::IMVEC2:
			*(ImVec2*)item.m_pObj = StringToImVec2(strValue.c_str());
			break;
		case Type::IMVEC4:
			*(ImVec4*)item.m_pObj = StringToImVec4(strValue.c_str());
		};
	}

	void Load() {
		const int bufSize = 64;
		char buf[bufSize];

		for (auto& item : g_items) {
			ZeroMemory(buf, bufSize);
			GetPrivateProfileStringA(item.m_category.c_str(), item.m_name.c_str(), "<default_null>", buf, bufSize, g_file);
			std::string strValue = buf;

			if (strValue != "<default_null>") {
				Deserialize(item, strValue);
			}
		}
	}

	void Save() {
		for (auto& item : g_items) {
			auto str = Serialize(item);
			WritePrivateProfileStringA(item.m_category.c_str(), item.m_name.c_str(), str.c_str(), g_file);
		}
	}
}

#endif // !CONFIG_HPP
