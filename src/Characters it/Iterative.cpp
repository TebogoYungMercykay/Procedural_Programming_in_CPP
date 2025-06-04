#include "Iterative.h"
#include <iostream>

namespace Iterative {
int length(const char *start) {
  bool isEmpty = start == NULL;
  int len = 0;
  if (isEmpty) {
    return 0;
  } else {
    while (start[len] != '\0') {
      len++;
    }
    return len;
  }
}

char find(const char *start, int index) {
  bool isEmpty = start == NULL || index < 0;
  int i = 0;
  if (isEmpty) {
    return '\0';
  } else {
    while (start[i] != '\0') {
      bool isFound = (i == index);
      if (isFound) {
        return start[i];
      }
      i++;
    }
    return '\0';
  }
}

bool contains(const char *start, char letter) {
  bool isEmpty = start == NULL;
  int i = 0;
  if (isEmpty) {
    return false;
  } else {
    while (start[i] != '\0') {
      bool isFound = (start[i] == letter);
      if (isFound) {
        return true;
      }
      i++;
    }
    return false;
  }
}

void printout(const char *start) {
  bool isEmpty = start == NULL;
  int i = 0;
  if (isEmpty) {
    std::cout << std::endl;
    return;
  } else {
    while (start[i] != '\0') {
      std::cout << start[i];
      i++;
    }
    std::cout << std::endl;
  }
}

void reverseWord(char *start, char *result) {
  bool isEmpty = start == NULL || result == NULL;
  if (isEmpty) {
    return;
  } else {
    int len = length(start);
    for (int i = 0; i < len; i++) {
      result[i] = start[len - 1 - i];
    }
    result[len] = '\0';
  }
}

int countOccurrences(const char *start, char c) {
  bool isEmpty = start == NULL;
  int count = 0;
  int i = 0;
  if (isEmpty) {
    return 0;
  } else {
    while (start[i] != '\0') {
      bool isFound = (start[i] == c);
      if (isFound) {
        count++;
      }
      i++;
    }
    return count;
  }
}

char mostFrequentLetter(const char *start) {
  bool isEmpty = start == NULL || start[0] == '\0';
  int maxCount = 0;
  int i = 0;
  if (isEmpty) {
    return '\0';
  } else {
    char maxChar = start[0];

    while (start[i] != '\0') {
      int currentCount = countOccurrences(start, start[i]);
      bool isMax = (currentCount > maxCount);
      if (isMax) {
        maxCount = currentCount;
        maxChar = start[i];
      }
      i++;
    }

    return maxChar;
  }
}

void printInReverse(const char *start) {
  bool isEmpty = start == NULL;
  if (isEmpty) {
    std::cout << std::endl;
    return;
  } else {
    int len = length(start);
    for (int i = len - 1; i >= 0; i--) {
      std::cout << start[i];
    }
    std::cout << std::endl;
  }
}

char *findLastLetter(char *start) {
  bool isEmpty = start == NULL || start[0] == '\0';
  int i = 0;
  if (isEmpty) {
    return start;
  } else {
    while (start[i + 1] != '\0') {
      i++;
    }
    return &start[i];
  }
}

const char *findLastLetter(const char *start) {
  bool isEmpty = start == NULL || start[0] == '\0';
  int i = 0;
  if (isEmpty) {
    return start;
  } else {
    while (start[i + 1] != '\0') {
      i++;
    }
    return &start[i];
  }
}

bool isPalindrome(const char *start) {
  bool isEmpty = start == NULL;
  if (isEmpty) {
    return false;
  } else {
    int len = length(start);
    bool isSingleChar = (len == 1);
    if (isSingleChar) {
      return true;
    } else {
      for (int i = 0; i < len / 2; i++) {
        bool isEqual = (start[i] == start[len - 1 - i]);
        if (!isEqual) {
          return false;
        }
      }
      return true;
    }
  }
}

int charactersBetween(const char *p1, const char *p2) {
  bool isEmpty = p1 == NULL || p2 == NULL || p1 == p2;
  int count = 0;
  if (isEmpty) {
    return 0;
  } else {
    const char *current = p1 + 1;

    while (count < 100 && *current != '\0') {
      ++count;
      bool isEqual = (current == p2);
      if (isEqual) {
        return count;
      }
      ++current;
    }
    return 100;
  }
}
} // namespace Iterative
