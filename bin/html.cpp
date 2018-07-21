/*
 * Class: HTML
 * File: html.cpp
 * Author: So Chigusa
 * Description: html operation class
 *
 * Created on 2018/6/30
 */

#include "html.h"

void HTML::split(std::vector<std::string> &v, const std::string &buf, char sep) {
  v.resize(0);
  std::stringstream ss(buf);
  std::string mbuf;
  while(getline(ss, mbuf, sep)) { if(mbuf != "") v.push_back(mbuf); }
}

std::string HTML::getYYYYMMDD(time_t t) {
  struct tm* localTime = std::localtime(&t);
  int yyyy = localTime->tm_year + 1900;
  int mm = localTime->tm_mon + 1;
  int dd = localTime->tm_mday;
  return std::to_string(yyyy) + "/" + std::to_string(mm) + "/" + std::to_string(dd);
}

void HTML::insertFromFile(std::stringstream &ss, std::string &bufline) {
  std::string buf;
  std::vector<std::string> val;
  split(val, bufline, ' ');
  std::ifstream ifs("../"+val[4]);
  while(std::getline(ifs, buf)) ss << buf << std::endl;
}

void HTML::extract_body(const std::string &strtemp, const std::string &strout) {
  std::ifstream ifs(strtemp);
  std::stringstream ss;
  std::string strBufferLine;
  std::vector<std::string> val;
  bool isbody = false;

  ss << "<div id=\"content\">" << std::endl;
  ss << "<div class=\"article\">" << std::endl;
  
  while(std::getline(ifs, strBufferLine)) {
    if((int)strBufferLine.find("</body>") != -1) { isbody = false; }
    if(isbody) { ss << strBufferLine << std::endl; }
    if((int)strBufferLine.find("<body>") != -1) { isbody = true; }
  }

  ss << "</div>" << std::endl; // class = article
  ss << "</div>" << std::endl; // id = content
  
  std::ofstream ofs(strout);
  ofs << ss.str();
}

void HTML::update_html(const std::string &strtemp, const std::string &strout,
		       const std::string &cname) {
  std::ifstream ifs(strtemp);
  std::stringstream ss;
  std::string strBufferLine;
  std::vector<std::string> val;

  while(std::getline(ifs, strBufferLine)) {
    ss << strBufferLine << std::endl;

    // insert from files
    if((int)strBufferLine.find("<!-- insertion below : ") != -1) {
      insertFromFile(ss, strBufferLine);
    }
    
    // add recent activities
    if((int)strBufferLine.find("<!-- Recent Activities below -->") != -1) {
      std::ifstream iflog("../research/research.log");
      ss << "<article>" << std::endl;
      for(int i = 0; i < 4; i++) {
	std::getline(iflog, strBufferLine);
	split(val, strBufferLine, ';');
	ss << "  <section>" << std::endl;
	
	if(val[1] == "Paper") {
	  ss << "    <span class=\"date\">" // date
	     << getYYYYMMDD((time_t)stol(val[0])) << "</span>" << std::endl;
	  ss << "    <h1><a href=\"https://arxiv.org/abs/" << val[4] << "\" "
	     << "target=_blank>arXiv:" << val[4] << "</a></h1>" << std::endl; // arXiv #
	  ss << "    <p>" << std::endl;
	  ss << "      " << val[3] << "<br>" << std::endl; // authors
	  ss << "      <i>" << val[2] << "</i>" << std::endl; // title
	  ss << "    </p>" << std::endl;	
	} else if(val[1] == "Talk") {
	  ss << "    <span class=\"date\">" << val[3] << "</span>" << std::endl; // date
	  ss << "    <h1>Talk: " << val[4] << "</a></h1>" << std::endl;
	  ss << "    <p>" << std::endl;
	  ss << "      <i>" << val[2] << "</i>" << std::endl;
	  ss << "    </p>" << std::endl;
	}
	
	ss << "  </section>" << std::endl;
      }
      ss << "</article>" << std::endl;
    }

    // add recent tips
    if((int)strBufferLine.find("<!-- Recent Tips below -->") != -1) {
      std::ifstream iflog("../tips/tips.log");
      ss << "<article>" << std::endl;
      for(int i = 0; i < 2; i++) {
	std::getline(iflog, strBufferLine);
	split(val, strBufferLine, ';');
	ss << "  <section>" << std::endl;
	ss << "    <span class=\"date\">" // date
	   << getYYYYMMDD((time_t)stol(val[0])) << "</span>" << std::endl;
	ss << "    <h1><a href=\"tips/" << val[1] << ".html\">"
	   << val[1] << "</a></h1>" << std::endl; // title
	ss << "    <p>" << std::endl;
	ss << "      " << val[2] << std::endl; // long title
	ss << "    </p>" << std::endl;
	ss << "  </section>" << std::endl;
      }
      ss << "</article>" << std::endl;
    }

    // add paper info
    if((int)strBufferLine.find("<!-- Papers below -->") != -1) {
      std::ifstream iflog("../research/research.log");
      while(std::getline(iflog, strBufferLine)) {
	split(val, strBufferLine, ';');
	if(val[1] == "Paper") {
	  ss << "    <li>" << val[3] << "<br>" << std::endl; // authors
	  ss << "      <i>" << val[2] << ",</i><br>" << std::endl; // title
	  ss << "      <a href=\"https://arxiv.org/abs/" << val[4] << "\" target=_blank>[arXiv:" << val[4] << "]</a>." << std::endl; // arXiv #
	  ss << "    </li>" << std::endl;
	}
      }
    }

    // add talk info
    if((int)strBufferLine.find("<!-- Talks below -->") != -1) {
      std::ifstream iflog("../research/research.log");
      while(std::getline(iflog, strBufferLine)) {
	split(val, strBufferLine, ';');
	if(val[1] == "Talk") {
	  ss << "    <li><i>" << val[2] << ",</i><br>" << std::endl; // title
	  ss << "      " << val[4] << " (" << val[3] << ").</li>" << std::endl; // location and date
	}
      }
    }

    // add tips menu
    if((int)strBufferLine.find("<!-- Tips menu below -->") != -1) {
      ss << "    <nav>" << std::endl;
      ss << "      <h3>Tips Menu</h3>" << std::endl;
      ss << "      <ul>" << std::endl;
      std::ifstream iflog("../tips/tips.log");
      while(std::getline(iflog, strBufferLine)) {
	split(val, strBufferLine, ';');
	ss << "      <li><a href=\"" << val[1] << ".html\">"
	   << val[1] << "</a></li>" << std::endl;
      }
      ss << "       </ul>" << std::endl;
      ss << "    </nav>" << std::endl;
    }
    
    // add tips / git contents
    if((int)strBufferLine.find("<!-- Contents below -->") != -1) {
      std::ifstream iftext(cname);
      bool body = false;
      while(std::getline(iftext, strBufferLine)) {
	if((int)strBufferLine.find("</body>") != -1) body = false;
	if(body) ss << "    " << strBufferLine << std::endl;
	if((int)strBufferLine.find("<body>") != -1) body = true;
      }
    }
  }

  std::ofstream ofs(strout);
  ofs << ss.str();
}

void HTML::update_cv() {
  std::ifstream ifs("../cv/cv_temp.tex");
  std::stringstream ss;
  std::string strBufferLine;
  std::vector<std::string> val;

  while(std::getline(ifs, strBufferLine)) {
    ss << strBufferLine << std::endl;

    // current age (at LO approximation)
    if((int)strBufferLine.find("% Age below") != -1) {
      struct tm birthdayStruct = { 0, 0, 0, 22, 5, 1992 - 1900 };
      time_t birthday = std::mktime(&birthdayStruct);
      time_t now = std::time(nullptr);
      int ageLO = (int)((now - birthday) / (365. * 24 * 60 * 60));
      ss << "  Age: & " << ageLO << " \\\\" << std::endl;
    }
      
    // add talks    
    if((int)strBufferLine.find("% Talks below") != -1) {
      std::ifstream iflog("../research/research.log");
      while(std::getline(iflog, strBufferLine)) {
	split(val, strBufferLine, ';');
	if(val[1] == "Talk") {
	  auto pos = val[4].find(" @");
	  if (pos != std::string::npos) val[4].replace(pos, 2, ",");
	  ss << " \\item ``" << val[2] // title
	     << "'', " << val[4] << std::endl; // conference
	}
      }
    }
  }

  std::ofstream ofs("../cv/cv.tex");
  ofs << ss.str();
}

void HTML::update_bibtex(const char *buffer) {
  std::stringstream ss;
  std::string strBufferLine;
  std::ifstream ifs("../cv/cv.bib");
  ss << buffer << std::endl << std::endl;
  while(std::getline(ifs, strBufferLine)) ss << strBufferLine << std::endl;
  std::ofstream ofs("../cv/cv.bib");
  ofs << ss.str();
}

void HTML::update_tipslog() {
  std::ifstream iflog("../tips/tips.log");
  std::string strBufferLine;
  std::vector<std::string> val;
  bool firstLine = true;
  while(std::getline(iflog, strBufferLine)) {
    split(val, strBufferLine, ';');
    if(firstLine) { // Preserve most recent as index.html
      update_html("../tips/index_temp.html", "../tips/index.html",
		  "../tips/source/"+val[1]+".html");
      firstLine = false;
    }
    update_html("../tips/index_temp.html", "../tips/"+val[1]+".html",
		"../tips/source/"+val[1]+".html");
  }
}

void HTML::update_diarylog() {
  std::ifstream iflog("../diary/diary.log");
  std::string strBufferLine;
  std::vector<std::string> val;
  bool firstLine = true;
  int npage = 1;
  while(std::getline(iflog, strBufferLine)) {
    split(val, strBufferLine, ';');
    if(firstLine) { // Preserve most recent as index.html
      update_html("../diary/index_temp.html", "../diary/index.html",
		  "../diary/source/"+val[1]+".html");
      firstLine = false;
    } else {
      extract_body("../diary/source/"+val[1]+".html",
		   "../diary/page-"+std::to_string(npage)+".html");
    }
    npage++;
  }
}
