/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainWindow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:14:41 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 23:29:30 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <QAction>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QWidget>
#include <QtWidgets>
#include <QString>
#include <QtCharts/QChart>

#include <cstdlib>

#include "MainWindow.hpp"

MainWindow::MainWindow() : QMainWindow(0), _ram_chart_view(0),
	_cpu_chart_view(0), _pony_movie(0)
{
	setWindowTitle(tr("ft_gkrellm"));
	setMinimumSize(700, 1000);
	resize(700, 1000);
	_central = new QWidget;
	setCentralWidget(_central);
	
	_createActions();
	_createMenus();
	menuBar()->setNativeMenuBar(false);

	_createSubs();

	QVBoxLayout*	_cent_layout = new QVBoxLayout();
	_cent_layout->addWidget(_host_sub);
	_cent_layout->addWidget(_cpu_sub);
	_cent_layout->addWidget(_ram_sub);
	_cent_layout->addWidget(_net_sub);
	_cent_layout->addWidget(_pony_sub);
	_central->setLayout(_cent_layout);
}

MainWindow::MainWindow(const MainWindow& src)
{
	*this = src;
}

MainWindow::~MainWindow()
{
}

MainWindow& MainWindow::operator=(const MainWindow& rhs)
{
	static_cast<void>(rhs);
	return *this;
}

void	MainWindow::set_hostname(std::string& s)
{
	_username_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_username(std::string& s)
{
	_hostname_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_os_infos(std::string& s)
{
	_os_infos_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_date_time(std::string& s)
{
	_date_time_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_cpu_model(std::string& s)
{
	_cpu_model_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_cpu_n_cores(std::string& s)
{
	s = "Cores : "+s;
	_cpu_n_cores_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_cpu_load_core(std::string& s0, std::string& s1,
			std::string& s2, std::string& s3)
{
	//_cpu_load_core_lbl->setText(QString(s.c_str()));
	QtCharts::QChart *chart = new QtCharts::QChart();

	QtCharts::QBarSet *set0 = new QtCharts::QBarSet("Core 0");
	*set0 << atol(s0.c_str());
	QtCharts::QBarSet *set1 = new QtCharts::QBarSet("Core 1");
	*set1 << atol(s1.c_str());
	QtCharts::QBarSet *set2 = new QtCharts::QBarSet("Core 2");
	*set2 << atol(s2.c_str());
	QtCharts::QBarSet *set3 = new QtCharts::QBarSet("Core 3");
	*set3 << atol(s3.c_str());
	
	QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
	series->append(set0);
	series->append(set1);
	series->append(set2);
	series->append(set3);
	chart->addSeries(series);
	chart->setTitle("CPU (%)");
	QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
	chart->setAxisY(axisY, series);
	axisY->setRange(0, 100);
	axisY->applyNiceNumbers();

	chart->createDefaultAxes();
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	if (_cpu_chart_view) {
		QtCharts::QChart *old_chart = _cpu_chart_view->chart();
		_cpu_chart_view->setChart(chart);
		if (old_chart) {
			delete old_chart;
		}
	} else {
		delete chart;
	}

}

void	MainWindow::set_ram_amount(std::string& s)
{
	s = "Tot: " + s + " Mb ";
	_ram_amount_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_ram_used(std::string& s)
{
	s = "Used : " + s + " Mb ";
	_ram_used_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_ram_free(std::string& s)
{
	s = "Free : " + s + " Mb ";
	_ram_free_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_ram_perc(std::string& s)
{
	_ram_perc_lbl->setText(QString(s.c_str()) + " %");


	QtCharts::QChart *chart = new QtCharts::QChart();

	QtCharts::QBarSet *set0 = new QtCharts::QBarSet("RAM (%)");
	*set0 << atol(s.c_str());
	QtCharts::QHorizontalBarSeries *series = new QtCharts::QHorizontalBarSeries();
	series->append(set0);
	chart->addSeries(series);
	chart->setTitle("RAM (%)");
	QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis();
	chart->setAxisX(axisX, series);
	axisX->setRange(0, 100);
	axisX->applyNiceNumbers();

	chart->createDefaultAxes();
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);
	if (_ram_chart_view) {
		QtCharts::QChart *old_chart = _ram_chart_view->chart();
		_ram_chart_view->setChart(chart);
		if (old_chart) {
			delete old_chart;
		}
	} else {
		delete chart;
	}
}

void	MainWindow::set_net_n_ifaces(std::string& s)
{
	s = "Nb d'ifaces : " + s;
	_net_n_ifaces_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_net_pkts_in(std::string& s)
{
	s = "Packets in  : " + s;
	_net_pkts_in_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_net_pkts_out(std::string& s)
{
	s = "Packets out : " + s;
	_net_pkts_out_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_net_data_in(std::string& s)
{
	s = "Bytes in  : " + s;
	_net_data_in_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_net_data_out(std::string& s)
{
	s = "Bytes out : " + s;
	_net_data_out_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_net_en0_addr(std::string& s)
{
	s = "en0 : " + s;
	_net_en0_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_net_lo0_addr(std::string& s)
{
	s = "lo0 : " + s;
	_net_lo0_lbl->setText(QString(s.c_str()));
}

void	MainWindow::set_pony_data()
{
	//QImage myImage;
	//myImage.load("pony.gif");
	//_pony_lbl->setPixmap(QPixmap::fromImage(myImage));
	if (!_pony_movie)
	{
		_pony_movie = new QMovie("pony.gif");
		_pony_lbl->setMovie(_pony_movie);
	}
	_pony_movie->start();
}

void	MainWindow::init()
{
	this->show();
}

void	MainWindow::_createActions()
{
	_exit_act = new QAction(tr("E&xit"), this);
	_exit_act->setShortcuts(QKeySequence::Quit);
	_exit_act->setStatusTip(tr("Exit the application"));
	connect(_exit_act, SIGNAL(triggered()), this, SLOT(_exit()));
}

void	MainWindow::_createMenus()
{
	_file_menu = menuBar()->addMenu(tr("&File"));
	_file_menu->addAction(_exit_act);
}

void	MainWindow::_createSubs()
{
	_host_sub = new QGroupBox(tr("Host"));
	_hostname_lbl = new QLabel;
	_username_lbl = new QLabel;
	_os_infos_lbl = new QLabel;
	_date_time_lbl = new QLabel;

	QVBoxLayout*	host_lay = new QVBoxLayout();
	host_lay->addWidget(_hostname_lbl);
	host_lay->addWidget(_username_lbl);
	host_lay->addWidget(_os_infos_lbl);
	host_lay->addWidget(_date_time_lbl);
	_host_sub->setLayout(host_lay);

	////////////////////////////////////////////////////////////////////////////

	_cpu_sub = new QGroupBox(tr("Cpu"));
	_cpu_model_lbl = new QLabel;
	_cpu_n_cores_lbl = new QLabel;

	_cpu_chart_view = new QtCharts::QChartView();
	_cpu_chart_view->setRenderHint(QPainter::Antialiasing);

	QVBoxLayout*	cpu_lay = new QVBoxLayout;
	cpu_lay->addWidget(_cpu_model_lbl);
	cpu_lay->addWidget(_cpu_n_cores_lbl);
	cpu_lay->addWidget(_cpu_chart_view);
	_cpu_sub->setLayout(cpu_lay);

	////////////////////////////////////////////////////////////////////////////
	
	_ram_sub = new QGroupBox(tr("Ram"));
	_ram_amount_lbl = new QLabel;
	_ram_used_lbl = new QLabel;
	_ram_free_lbl = new QLabel;
	_ram_perc_lbl = new QLabel;

	QHBoxLayout*	ram_top_lay = new QHBoxLayout;
	ram_top_lay->addWidget(_ram_amount_lbl);
	ram_top_lay->addWidget(_ram_used_lbl);
	ram_top_lay->addWidget(_ram_free_lbl);
	ram_top_lay->addWidget(_ram_perc_lbl);

	_ram_chart_view = new QtCharts::QChartView();
	_ram_chart_view->setRenderHint(QPainter::Antialiasing);

	QVBoxLayout*	ram_lay = new QVBoxLayout;
	ram_lay->addLayout(ram_top_lay);
	ram_lay->addWidget(_ram_chart_view);
	_ram_sub->setLayout(ram_lay);

	////////////////////////////////////////////////////////////////////////////

	_net_sub = new QGroupBox(tr("Net"));
	_net_n_ifaces_lbl = new QLabel;
	_net_pkts_in_lbl = new QLabel;
	_net_pkts_out_lbl = new QLabel;
	_net_data_in_lbl = new QLabel;
	_net_data_out_lbl = new QLabel;
	_net_en0_lbl = new QLabel;
	_net_lo0_lbl = new QLabel;

	QHBoxLayout* net_top_lay = new QHBoxLayout;
	net_top_lay->addWidget(_net_n_ifaces_lbl);
	net_top_lay->addWidget(_net_en0_lbl);;
	net_top_lay->addWidget(_net_lo0_lbl);

	QVBoxLayout* net_lay = new QVBoxLayout;
	net_lay->addLayout(net_top_lay);
	net_lay->addWidget(_net_pkts_in_lbl);
	net_lay->addWidget(_net_pkts_out_lbl);
	net_lay->addWidget(_net_data_in_lbl);
	net_lay->addWidget(_net_data_out_lbl);
	_net_sub->setLayout(net_lay);

	////////////////////////////////////////////////////////////////////////////

	_pony_sub = new QGroupBox(tr("Pony"));
	_pony_lbl = new QLabel;
//	_pony_scene = new QGraphicsScene;
	QVBoxLayout* pony_lay = new QVBoxLayout;
	pony_lay->addWidget(_pony_lbl);
	_pony_sub->setLayout(pony_lay);
}

void	MainWindow::_exit()
{
	exit(0);
}
