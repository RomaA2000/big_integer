//
// Created by Роман Агеев on 2019-04-15.
//

#ifndef BIGINTEGER_BIGINTEGER_H
#define BIGINTEGER_BIGINTEGER_H
#include <iostream>
#include <string>
#include <vector>

class big_integer {
  bool sgn;
  typedef uint64_t main_type;
  typedef int64_t signed_main_type;
  typedef __uint128_t buffer_type;
  typedef __int128_t signed_buffer_type;
  static const main_type MAIN_MAX = UINT64_MAX;
  static const main_type MAIN_TYPE_SIZE = 64;
  static const buffer_type MAIN_DIGIT = (buffer_type)MAIN_MAX + (buffer_type) 1;
  std::vector<main_type> data;
  big_integer &mod_or_div(big_integer const &, bool);
  big_integer &part_add(big_integer const &);
  big_integer &part_sub(big_integer const &);
  big_integer div_short(main_type);
  void negate();
  main_type const &operator[](size_t) const;
  main_type &operator[](size_t);
  main_type safe_get(size_t) const;
  void pop_back();
  void push_back(main_type);
  main_type const &back() const;
  main_type &back();
  bool empty() const;
  void shrink_to_fit();
  void mov_right(size_t);
  void mov_left(size_t);
  void swap(big_integer &);
  bool is_two_pow();
  static inline bool is_number(char c);
  static inline big_integer moved(size_t);
  int32_t compare_by_abs(big_integer const&) const;
 public:
  big_integer &operator*=(main_type);
  big_integer &operator+=(main_type);
  big_integer &operator*=(int);
  big_integer();
  big_integer(std::vector<main_type> &, bool);
  big_integer(big_integer const &);
  big_integer(int);
  big_integer(uint32_t);
  big_integer(uint64_t);
  explicit big_integer(std::string const &);
  ~big_integer();
  size_t size() const;
  bool is_positive() const;
  bool is_zero() const;
  bool is_one() const;
  void clear();
  void to_addition();
  void invert_bytes();
  void back_from_addition();
  void increase_to_size(size_t);
  void increase_size_on(size_t);
  void abs();
  big_integer &operator=(big_integer const &);

  big_integer &operator+=(big_integer const &);
  big_integer &operator-=(big_integer const &);
  big_integer &operator*=(big_integer const &);
  big_integer &operator/=(big_integer const &);
  big_integer &operator%=(big_integer const &);

  big_integer &operator&=(big_integer const &);
  big_integer &operator|=(big_integer const &);
  big_integer &operator^=(big_integer const &);

  big_integer &abstract_binary(big_integer &, main_type (main_type, main_type));
  big_integer &operator<<=(int);
  big_integer &operator>>=(int);



  big_integer operator+() const;
  big_integer operator-() const;
  big_integer operator~() const;

  big_integer &operator++();
  const big_integer operator++(int);

  big_integer &operator--();
  const big_integer operator--(int);

  friend bool operator==(big_integer const &, big_integer const &);
  friend bool operator!=(big_integer const &, big_integer const &);
  friend bool operator<(big_integer const &, big_integer const &);
  friend bool operator>(big_integer const &, big_integer const &);
  friend bool operator<=(big_integer const &, big_integer const &);
  friend bool operator>=(big_integer const &, big_integer const &);

  friend big_integer operator|(big_integer , big_integer const &);
  friend big_integer operator&(big_integer , big_integer const &);
  friend big_integer operator^(big_integer , big_integer const &);

  friend big_integer operator+(big_integer , big_integer const &);
  friend big_integer operator-(big_integer , big_integer const &);
  friend big_integer operator*(big_integer , big_integer const &);
  friend big_integer operator/(big_integer , big_integer const &);
  friend big_integer operator%(big_integer , big_integer const &);


  friend big_integer operator<<(big_integer , int);
  friend big_integer operator>>(big_integer , int);

  friend big_integer abs(big_integer const &);

  friend std::ostream &operator<<(std::ostream &, const big_integer &);
  friend std::istream &operator>>(std::istream &, big_integer &);

  friend std::string to_string(big_integer in);
};

#endif //BIGINTEGER_BIGINTEGER_H
