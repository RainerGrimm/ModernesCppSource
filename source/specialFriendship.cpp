// specialFriendship.cpp

#include <iostream>

template <typename T> void myFriendFunction(T);
template <typename U> class MyFriend;


class GrantingFriendshipAsClass {

  friend void myFriendFunction<>(int);
  friend class MyFriend<int>;

private:
  std::string secret{"Secret from GrantingFriendshipAsClass."};

};

template <typename T>
class GrantingFriendshipAsClassTemplate {

  friend void myFriendFunction<>(int);
  friend class MyFriend<int>;
  friend class MyFriend<T>;

private:
  std::string secret{"Secret from GrantingFriendshipAsClassTemplate."};

};

template <typename T>
void myFriendFunction(T){
  GrantingFriendshipAsClass myFriend;
  std::cout << myFriend.secret << '\n';

  GrantingFriendshipAsClassTemplate<T> myFriend1;
  std::cout << myFriend1.secret << '\n';
}

template <typename T>
class MyFriend{
public:
  MyFriend(){
    GrantingFriendshipAsClass myFriend;
    std::cout << myFriend.secret << '\n';

    GrantingFriendshipAsClassTemplate<int> myFriendInt;
    std::cout << myFriendInt.secret << '\n';

    GrantingFriendshipAsClassTemplate<T> myFriendT;
    std::cout << myFriendT.secret << '\n';
  }
};

int main() {

  std::cout << '\n';

  int a{2011};
  myFriendFunction(a);

  MyFriend<int> myFriend;

  std::cout << '\n';

}
