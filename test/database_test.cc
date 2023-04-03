/*******************************************************************
 *  Copyright(c) 2023 zdy All rights reserved.
 ******************************************************************/

#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <future>

struct Row {
  Row() : a_(0), b_(0) { }
  Row(int a, int b) : a_(a), b_(b) { }
  int a_;
  int b_;
};

// 仿函数，用于比较Row的a_成员变量
class CmpRowA {
public:
  bool operator()(const Row& row1, const Row& row2) {
    return row1.a_ < row2.a_;
  }
};
// 仿函数，用于比较Row的b_成员变量
class CmpRowB {
public:
  bool operator()(const Row& row1, const Row& row2) {
    return row1.b_ < row2.b_;
  }
};

/**
 * 任务 1
 * 基于以下 C 程序框架, 我们希望你实现 task1() 这个函数, 它把 rows 中所有满⾜ b >= 10 &&
 * b < 50 并且 a == 1000 || a == 2000 || a == 3000 的⾏的内容都打印到终端
 *
 * 思路：
 * 方法一、直接循环遍历判断
 * 方法二、使用线程池，分割数组，让多线程并发计算提高效率
 */
void Task1(const std::vector<Row>& rows) {
  for (size_t i = 0; i < rows.size(); ++i) {
    if (rows[i].a_ == 1000 || rows[i].a_ == 2000 || rows[i].a_ == 3000 &&
      rows[i].b_ >= 10 && rows[i].b_ < 50) {
      std::cout << rows[i].a_ << "-" << rows[i].b_ << std::endl;
    }
  }
}

/**
 * 任务 2
 * 在任务 1 的基础上, 如果输⼊的参数 rows 已经按照(a, b) 进⾏过排序, 请实现 task2(), 对
 * task1() 的执⾏性能进⾏优化.⽰例输⼊(再次提醒, 实际输⼊为海量数据)
 *
 * 思路：
 * 条件主要分为两部分：判断 a == 1000 || a == 2000 || a == 3000和b >= 10 && b < 50，
 * 即将判断分为a和b的判断，b为范围判断；并且输入都为有序，因此使用二分法查找最快，
 * 找到满足a的左右范围下标（分别为三组： a=1000、a=2000、a=3000），
 * 再对这三组的b进行二分查找，找到对应下标，则得到三组满足的结果，依次打印；
 * 其中因为a的要求为三组，可以同时使用三组线程异步来优化提高性能
 */

 /**
  * 功能描述: 打印rows中，某元素a为入参a，b为入参[b_begin, b_end)
  * @param [input]rows: 输入的rows数组
  * @param [input]a: 指定a的值，只有符合条件的才会打印
  * @param [input]b_begin: 指定b的起始下标
  * @param [input]b_end: 指定b的结束下标
  * @return void
  */
void Find1(const std::vector<Row>& rows, int a, int b_begin, int b_end) {
  // 使用STL的二分查找找到第一个等于a的下标
  auto& iter_first_a = std::lower_bound(rows.begin(), rows.end(), Row(a, 0), CmpRowA());
  // 使用STL的二分查找找到第一个大于a的下标
  auto& iter_end_a = std::upper_bound(rows.begin(), rows.end(), Row(a, 0), CmpRowA());
  if (iter_first_a == rows.end()) {
    return;
  }
  // 使用STL的二分查找找到第一个等于b的下标
  auto& iter_first_b = std::lower_bound(iter_first_a, iter_end_a, Row(0, b_begin), CmpRowB());
  // 使用STL的二分查找找到第一个大于b的下标
  auto& iter_end_b = std::upper_bound(iter_first_a, iter_end_a, Row(0, b_end), CmpRowB());
  if (iter_first_b == rows.end()) {
    return;
  }
  for (; iter_first_b < iter_end_b; ++iter_first_b) {
    // 如果需要在打印时保证线程安全，则在此加锁，也可以只让主线程打印
    std::cout << iter_first_b->a_ << "-" << iter_first_b->b_ << std::endl;
  }
}

void Task2(std::vector<Row>& rows) {
  // 使用STL的异步操作，同时去打印1000、2000、3000的结果
  std::future<void> future_find_1000(std::async(Find1, rows, 1000, 10, 50));
  std::future<void> future_find_2000(std::async(Find1, rows, 2000, 10, 50));
  std::future<void> future_find_3000(std::async(Find1, rows, 3000, 10, 50));

  // 这里阻塞等待三个future的结果
  future_find_1000.get();
  future_find_2000.get();
  future_find_3000.get();
}

/**
 * 任务 3
 * 在任务 2 的基础上, 我们期望你打印出的匹配⾏是按照 b 列进⾏排序的, 请实现 task3().
 *
 * 思路：
 * 在任务2的基础上，将打印的工作放在主线程，三个线程只去查找满足条件的三组下标范围
 * 主线程得到三组下标范围后，按顺序打印结果
 */

 /**
  * 功能描述: 返回在rows中，某元素a为入参a，b为入参[b_begin, b_end)的范围下标
  * @param [input]rows: 输入的rows数组
  * @param [input]a: 指定a的值，只有符合条件的才会打印
  * @param [input]b_begin: 指定b的起始下标
  * @param [input]b_end: 指定b的结束下标
  * @return std::pair<int, int>: 左闭右开的范围
  */
std::pair<int, int> Find2(const std::vector<Row>& rows, int a, int b_begin, int b_end) {
  auto& iter_first_a = std::lower_bound(rows.begin(), rows.end(), Row(a, 0), CmpRowA());
  auto& iter_end_a = std::upper_bound(rows.begin(), rows.end(), Row(a, 0), CmpRowA());
  if (iter_first_a == rows.end()) {
    return { 0, 0 };
  }
  int index_first_b = std::lower_bound(iter_first_a, iter_end_a, Row(0, b_begin), CmpRowB()) - rows.begin();
  int index_end_b = std::upper_bound(iter_first_a, iter_end_a, Row(0, b_end), CmpRowB()) - rows.begin();

  return { index_first_b, index_end_b };
}

void Task3(std::vector<Row>& rows) {
  // 异步，获取三组下标
  std::future<std::pair<int, int>> future_find_1000(std::async(Find2, rows, 1000, 10, 50));
  std::future<std::pair<int, int>> future_find_2000(std::async(Find2, rows, 2000, 10, 50));
  std::future<std::pair<int, int>> future_find_3000(std::async(Find2, rows, 3000, 10, 50));
  // 阻塞等待结果
  std::pair<int, int> pair_1000 = future_find_1000.get();
  std::pair<int, int> pair_2000 = future_find_2000.get();
  std::pair<int, int> pair_3000 = future_find_3000.get();
  // 顺序打印三个数组
  while (pair_1000.first < pair_1000.second ||
    pair_2000.first < pair_2000.second ||
    pair_3000.first < pair_3000.second) {
    std::pair<int, int>* min_pair;
    int min = INT_MAX;
    // 判断最小的值并打印
    if (pair_1000.first < pair_1000.second && min > rows[pair_1000.first].b_) {
      min_pair = &pair_1000;
      min = rows[pair_1000.first].b_;
    }
    if (pair_2000.first < pair_2000.second && min > rows[pair_2000.first].b_) {
      min_pair = &pair_2000;
      min = rows[pair_2000.first].b_;
    }
    if (pair_3000.first < pair_3000.second && min > rows[pair_3000.first].b_) {
      min_pair = &pair_3000;
      min = rows[pair_3000.first].b_;
    }
    std::cout << rows[min_pair->first].a_ << "-" << rows[min_pair->first].b_ << std::endl;
    ++(min_pair->first);
  }
  return;
}
