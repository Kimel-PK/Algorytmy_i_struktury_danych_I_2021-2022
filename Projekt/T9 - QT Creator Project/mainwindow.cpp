#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "T9Trie.hpp"
#include "WordsList.hpp"

using namespace std;

/*
	Klawiatura telefonu
	2 - abc
	3 - def
	4 - gh
	5 - ijk
	6 - lmno
	7 - pqrs
	8 - tuv
	9 - wxyz
	0 - spacja
	* - następne słowo
	# - zmaż znak
*/

QTextEdit* text_field;

string sms_text = "";

// słownik
T9Trie T9;

void LoadDictionary (string path) {
	
	ifstream read;
	string word;
	int frequency;
	
	read.open(path);
	
	if (!read) {
	   exit(1);
	}
	
	int i = 0;
	while (!read.eof()) {
		
		read >> word;
		read >> frequency;
		
		T9.Add(word, frequency);
		i++;
	}
	
	cout << "Pomyślnie wczytano " << i << " słów" << endl;
	read.close();

}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	
	text_field = ui->text_field;
	
	string file_name = QFileDialog::getOpenFileName(this, tr("Wybierz plik słownika"), "./", tr("Plik tekstowy (*.txt)")).toStdString();
	
	LoadDictionary(file_name);
	
	T9.Reset();
}

MainWindow::~MainWindow() {
	delete ui;
}

void ShowSMS () {
	
	if (T9.GetWord() != "") {
		text_field->setText(QString::fromStdString(sms_text + "<b>" + T9.GetWord() + "</b>"));
	} else {
		text_field->setText(QString::fromStdString(sms_text));
	}
}

void MainWindow::on_button_0_clicked() {
	sms_text += T9.GetWord() + " ";
	T9.Reset();
	ShowSMS();
}

void MainWindow::on_button_1_clicked() {
	ShowSMS();
}

void MainWindow::on_button_2_clicked() {
	T9.Next(0);
	ShowSMS ();
}

void MainWindow::on_button_3_clicked() {
	T9.Next(1);
	ShowSMS ();
}

void MainWindow::on_button_4_clicked() {
	T9.Next(2);
	ShowSMS ();
}

void MainWindow::on_button_5_clicked() {
	T9.Next(3);
	ShowSMS ();
}

void MainWindow::on_button_6_clicked() {
	T9.Next(4);
	ShowSMS ();
}

void MainWindow::on_button_7_clicked() {
	T9.Next(5);
	ShowSMS ();
}

void MainWindow::on_button_8_clicked() {
	T9.Next(6);
	ShowSMS ();
}

void MainWindow::on_button_9_clicked() {
	T9.Next(7);
	ShowSMS ();
}

void MainWindow::on_button_asterix_clicked() {
	T9.NextWord();
	ShowSMS ();
}

void MainWindow::on_button_hash_clicked() {
	if (T9.GetWord() == "" && sms_text.size() > 0) {
		char last_char = sms_text.at(sms_text.size() - 1);
		if (last_char == ' ') {
			sms_text.pop_back();
		} else {
			
			int i = sms_text.size() - 1;
			while (i != 0 && !isspace(sms_text.at(i))) {
			  --i;
			}
			
			cout << sms_text << endl;
			cout << "i: " << i << endl;
			
			string last_word;
			
			if (i == 0) {
				last_word = sms_text;
				sms_text = "";
			} else {
				last_word = sms_text.substr(i + 1);
				sms_text = sms_text.substr (0, i + 1);
			}
			
			cout << "sms_text: '" << sms_text << "'" << endl;
			cout << "last_word: '" << last_word << "'" << endl;
			
			T9.Find(last_word);
			ShowSMS();
			return;
		}
	}
	T9.Prev();
	ShowSMS ();
}