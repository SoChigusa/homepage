/*
 * Class: HTML
 * File: html.h
 * Author: So Chigusa
 * Description: html operation class
 *
 * Created on 2018/6/30
 */

#ifndef HTML_H
#define HTML_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class HTML {
 private:
  HTML();
 public:
  static void split(std::vector<std::string> &, const std::string &buf, char sep);
  static std::string getYYYYMMDD(time_t);
  static void insertFromFile(std::stringstream &, std::string &);
  static void update_html(const std::string &, const std::string &,
			  const std::string &cname = "");
  static void update_tipslog();
};

#endif
