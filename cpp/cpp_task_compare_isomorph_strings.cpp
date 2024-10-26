// burluckij@gmail.com

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <unordered_map>

// ���� ��� ������ s � t. ���������� ��������� �� ���.

// �����������:
// ��� ������ s � t ���������� �����������, ���� ����� ������� ������ �������� � ������ s,
// ����� �������� ������ t, ��� ����:
// 1. ��� ��������� ����������� ������� ������ ���� �������� ���������� ��������
// 2. ������� ��� ������ ������� �� ����� ���� �������� �� ���� � ��� �� ������
// 3. ������ ����� ���� ������� ��� �� ����


// �������:
// s = "egg", t = "add" -> True
// s = "foo", t = "bar" -> False
// s = "paper", t = "title" -> True
// -----------------------------
// s = "foooww", t = "baaarr" -> true
// s = "{f}xooow(f)", t = "{b}yaaar(y)" -> false
// s = "{f}xooow(f)", t = "{b}yaaar(f)" -> false
// s = "bar", t = "foo" -> False


bool compare(const std::string& s1, const std::string& s2)
{
	if (s1.size() != s2.size() || s1.empty() || s2.empty()) {
		return false;
	}
	std::unordered_map<char, char> letters, used;
	for (int i = 0; i < s1.size(); ++i) {
		if (letters.count(s1[i]) == 0) {
			if (used.count(s2[i]) == 0) {
				letters[s1[i]] = s2[i];
				used[s2[i]] = s1[i];
			} else {
				return false;
			}
		} else {
			if (letters[s1[i]] != s2[i]) {
				return false;
			}
		}
	}
	return true;
}

void do_test(const std::string& s1, const std::string& s2)
{
	bool result = compare(s1, s2);
	printf("\n'%s' : '%s' -> '%s'\n", s1.c_str(), s2.c_str(), result ? "true" : "false");
}

int main()
{
	do_test("egg", "add");
	do_test("foo", "bar");
	do_test("paper", "title");

	do_test("foooww", "baaarr!");
	do_test("fxooowf", "baaarr");
	do_test("fxooowf", "byaaary");

	getchar();
}


