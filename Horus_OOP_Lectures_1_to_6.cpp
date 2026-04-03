#include <iostream>
#include <string>

using namespace std;

// --- المحاضرة 4 & 5: تعريف الكلاس والتغليف (Encapsulation) ---
class Student {
protected: // المحاضرة 6: Protected تسمح للأبناء برؤية البيانات
    string name;
    int id;
    float* grades; // المحاضرة 1 & 2: استخدام المؤشرات (Pointers)
    int subjectsCount;

public:
    // المحاضرة 5: المنشئ (Constructor) مع تخصيص ذاكرة ديناميكية
    Student(string n, int i, int count) {
        name = n;
        id = i;
        subjectsCount = count;
        grades = new float[subjectsCount]; // المحاضرة 1: Dynamic Memory Allocation
        cout << "[System] Student " << name << " Created & Memory Allocated.\n";
    }

    // المحاضرة 6: المهدم (Destructor) لتجنب تسريب الذاكرة (Memory Leak)
    ~Student() {
        delete[] grades; // ضروري جداً لتنظيف الـ Heap
        cout << "[System] Memory Freed for Student " << name << ".\n";
    }

    void setGrade(int index, float value) {
        if (index >= 0 && index < subjectsCount) grades[index] = value;
    }
};

// --- المحاضرة 6: الوراثة (Inheritance) ---
// كلاس CSStudent يرث من Student (علاقة Is-A)
class CSStudent : public Student {
private:
    string technicalSkill;

public:
    // تمرير البيانات لمنشئ الأب (Base Class Constructor)
    CSStudent(string n, int i, int count, string skill) 
        : Student(n, i, count) { 
        technicalSkill = skill;
    }

    void displayInfo() {
        cout << "\n--- Student Info ---" << endl;
        cout << "Name: " << name << endl; // مسموح الوصول له لأنه Protected
        cout << "Field: Cybersecurity & AI" << endl;
        cout << "Skill: " << technicalSkill << endl;
        cout << "--------------------\n" << endl;
    }
};

int main() {
    // المحاضرة 1 & 2: التعامل مع الـ Pointers والكائنات
    // إنشاء كائن من الكلاس المشتق
    CSStudent* myStudent = new CSStudent("Omar Fathallah", 2026, 5, "Penetration Testing");

    myStudent->displayInfo();

    // المحاضرة 1: تذكر دائماً تنظيف الذاكرة يدوياً عند استخدام new
    delete myStudent; 

    return 0;
}
