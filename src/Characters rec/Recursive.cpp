#include "Recursive.h"
#include <iostream>

namespace Recursive {
int lengthHelper(const char *str, int index) {
  if (str[index] == '\0') {
    return index;
  } else {
    return lengthHelper(str, index + 1);
  }
}

int length(const char *str) {
  if (str == NULL) {
    return 0;
  } else {
    return lengthHelper(str, 0);
  }
}

char findHelper(const char *str, int target, int current) {
  if (str[current] == '\0') {
    return '\0';
  } else {
    if (current == target) {
      return str[current];
    } else {
      return findHelper(str, target, current + 1);
    }
  }
}

char find(const char *str, int index) {
  if (str == NULL || index < 0) {
    return '\0';
  } else {
    return findHelper(str, index, 0);
  }
}

bool containsHelper(const char *str, char letter, int index) {
  if (str[index] == '\0') {
    return false;
  } else {
    if (str[index] == letter) {
      return true;
    } else {
      return containsHelper(str, letter, index + 1);
    }
  }
}

bool contains(const char *str, char letter) {
  if (str == NULL) {
    return false;
  } else {
    return containsHelper(str, letter, 0);
  }
}

void printoutHelper(const char *str, int index) {
  if (str[index] == '\0') {
    return;
  } else {
    std::cout << str[index];
    printoutHelper(str, index + 1);
  }
}

void printout(const char *str) {
  if (str == NULL) {
    std::cout << std::endl;
    return;
  } else {
    printoutHelper(str, 0);
    std::cout << std::endl;
  }
}

void reverseWordHelper(char *str, char *result, int index, int len) {
  if (index >= len) {
    return;
  } else {
    result[index] = str[len - 1 - index];
    reverseWordHelper(str, result, index + 1, len);
  }
}

void reverseWord(char *str, char *result) {
  if (str == NULL || result == NULL) {
    return;
  } else {
    int len = length(str);
    reverseWordHelper(str, result, 0, len);
    result[len] = '\0';
  }
}

int countOccurrencesHelper(const char *str, char c, int index, int count) {
  if (str[index] == '\0') {
    return count;
  } else {
    if (str[index] == c) {
      count += 1;
    }
    return countOccurrencesHelper(str, c, index + 1, count);
  }
}

int countOccurrences(const char *str, char c) {
  if (str == NULL) {
    return 0;
  } else {
    return countOccurrencesHelper(str, c, 0, 0);
  }
}

void printInReverseHelper(const char *str, int index) {
  if (str[index] == '\0') {
    return;
  } else {
    printInReverseHelper(str, index + 1);
    std::cout << str[index];
  }
}

void printInReverse(const char *str) {
  if (str == NULL) {
    std::cout << std::endl;
    return;
  } else {
    printInReverseHelper(str, 0);
    std::cout << std::endl;
  }
}

char *findLastLetterHelper(char *str, int index) {
  if (str[index + 1] == '\0') {
    return &str[index];
  } else {
    return findLastLetterHelper(str, index + 1);
  }
}

char *findLastLetter(char *str) {
  if (str == NULL || str[0] == '\0') {
    return str;
  } else {
    return findLastLetterHelper(str, 0);
  }
}

const char *findLastLetterConstHelper(const char *str, int index) {
  if (str[index + 1] == '\0') {
    return &str[index];
  } else {
    return findLastLetterConstHelper(str, index + 1);
  }
}

const char *findLastLetter(const char *str) {
  if (str == NULL || str[0] == '\0') {
    return str;
  } else {
    return findLastLetterConstHelper(str, 0);
  }
}

int charactersBetween(const char *p1, const char *p2) {
  if (p1 == NULL || p2 == NULL || p1 == p2) {
    return 0;
  } else {
    const char *next = p1 + 1;

    if (next == p2) {
      return 1;
    } else {
      if (*next == '\0' || next == NULL) {
        return 100;
      } else {
        int rest = charactersBetween(next, p2);
        return (rest >= 100) ? 100 : 1 + rest;
      }
    }
  }
}
} // namespace Recursive
