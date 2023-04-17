// mvc.cpp

#include <iostream>
#include <string>
#include <unordered_map>


class DefectModel {
 public:                                                                      // (5)
     mutable std::unordered_map<std::string, std::string> defects_ = { {"XYZ" , "File doesn't get deleted."},
                                                                       {"XAB" , "Registry doesn't get created."},
                                                                      {"ABC" , "Wrong title get displayed."} };

    std::string getDefectComponent(const std::string& component) const {
        return defects_[component];
    }

    int getSummary() const {
        return defects_.size();
    }

    std::unordered_map<std::string, std::string> getAllDefects() const {
        return defects_;
    }

};

class DefectView {
 public:
    void showSummary(int num) const {
        std::cout << "Their are " + std::to_string(num) + " defects in total!\n";
    }
    
    void showDefectComponent(const std::string& defect) const {
        std::cout << "Defect of component: " + defect + '\n';
    }

    void showDefectList(const std::unordered_map<std::string, std::string>& defects) const {
        for (const auto& p: defects) {
            std::cout << "(" + p.first + ", " + p.second + ")\n";
        }
    }
};

class DefectController {
    const DefectModel& defectModel;
    const DefectView& defectView;
 public:
    DefectController(const DefectModel& defModel, const DefectView& defView):
                     defectModel{defModel}, defectView{defView} { }

    void showDefectComponent(const std::string& component) const {
        defectView.showDefectComponent(defectModel.getDefectComponent(component));    // (6)
    }

    void showDefectSummary() const {
        defectView.showSummary(defectModel.getSummary());                             // (7)
    }

    void showDefectList() const {
        defectView.showDefectList(defectModel.getAllDefects());                       // (8)
    }

};

int main() {

    std::cout << '\n';

    DefectModel defectModel;
    DefectView defectView;

    DefectController defectController(defectModel, defectView);  // (1)
    defectController.showDefectComponent("ABC");                 // (2)
    std::cout << '\n';
    defectController.showDefectSummary();                        // (3)
    std::cout << '\n';
    defectController.showDefectList();                           // (4)

    std::cout << '\n';

}