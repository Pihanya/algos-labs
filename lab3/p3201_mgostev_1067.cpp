#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

struct directory {
    map<string, directory *> sub_directories;
};

directory roots[50001];
long root_dir_num = 1, N;

directory *new_dir(directory *parent, const string& child_name) {
    auto &d = parent->sub_directories[child_name];
    // В случае, если встретился корневой элемент, его необходимо добавить в массив
    if (!d) {
        d = &roots[root_dir_num++];
    }

    return d;
}

void print_rec(directory *roots, string tabs = "") {
    for (auto root_dir : roots->sub_directories) {
        cout << tabs << root_dir.first << endl;
        print_rec(root_dir.second, tabs + " ");
    }
}

int main() {
    cin >> N;
    for (size_t i = 0; i < N; ++i) {
        string str, dir_str;
        cin >> str;

        stringstream stream(str);
        directory *dir = &roots[0];

        while (getline(stream, dir_str, '\\')) {
            dir = new_dir(dir, dir_str);
        }
    }

    print_rec(&roots[0]);
    return 0;
}