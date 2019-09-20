/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MainWindow.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skerkour <skerkour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 22:14:36 by skerkour          #+#    #+#             */
/*   Updated: 2015/06/28 23:26:36 by skerkour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINWINDOW_HPP
# define MAINWINDOW_HPP

# include <QAction>
# include <QMainWindow>
# include <QMenu>
# include <QWidget>
# include <QGroupBox>
# include <QVBoxLayout>
# include <QHBoxLayout>
# include <QLabel>
# include <string>

# include <QtCharts/QChartView>
# include <QtCharts/QBarSeries>
# include <QtCharts/QBarSet>
# include <QtCharts/QLegend>
# include <QtCharts/QBarCategoryAxis>
# include <QtCharts/QValueAxis>
# include <QtCharts/QHorizontalBarSeries>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
	MainWindow();
	MainWindow(const MainWindow& src);
	~MainWindow();

	MainWindow& operator=(const MainWindow& rhs);

	void	set_hostname(std::string& s);
	void	set_username(std::string& s);
	void	set_os_infos(std::string& s);
	void	set_date_time(std::string& s);
	void	set_cpu_model(std::string& s);
	void	set_cpu_n_cores(std::string& s);
	void	set_cpu_load_core(std::string& s0, std::string& s1,
				std::string& s2, std::string& s3);
	void	set_ram_amount(std::string& s);
	void	set_ram_used(std::string& s);
	void	set_ram_free(std::string& s);
	void	set_ram_perc(std::string& s);
	void	set_net_n_ifaces(std::string& s);
	void	set_net_pkts_in(std::string& s);
	void	set_net_pkts_out(std::string& s);
	void	set_net_data_in(std::string& s);
	void	set_net_data_out(std::string& s);
	void	set_net_en0_addr(std::string& s);
	void	set_net_lo0_addr(std::string& s);
	void	set_pony_data();

	void	init();

private:
	void	_createActions();
	void	_createMenus();
	void	_createSubs();

	QMenu*		_file_menu;
	QAction*	_exit_act;
	QWidget*	_central;
	QGroupBox	*_host_sub,
				*_cpu_sub,
				*_ram_sub,
				*_net_sub,
				*_pony_sub;

	QLabel		*_hostname_lbl,
				*_username_lbl,
				*_os_infos_lbl,
				*_date_time_lbl,
				*_cpu_model_lbl,
				*_cpu_n_cores_lbl,
				*_ram_amount_lbl,
				*_ram_used_lbl,
				*_ram_free_lbl,
				*_ram_perc_lbl,
				*_net_n_ifaces_lbl,
				*_net_pkts_in_lbl,
				*_net_pkts_out_lbl,
				*_net_data_in_lbl,
				*_net_data_out_lbl,
				*_net_en0_lbl,
				*_net_lo0_lbl,
				*_pony_lbl;
	QGraphicsScene	*_pony_scene;
	QtCharts::QChartView	*_ram_chart_view,
							*_cpu_chart_view;
	QMovie*		_pony_movie;

private slots:
	void	_exit();
};

#endif // MAINWINDOW_HPP
