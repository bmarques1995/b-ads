#pragma once

#include <QHash>
#include <QList>
#include <QString>
#include <QAbstractTableModel>

#include "API.h"
#include "ContainerWidget.h"
#include "SectionContent.h"
B_ADS_NAMESPACE_BEGIN
class ContainerWidget;
B_ADS_NAMESPACE_END

class SectionContentListModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	enum Column
	{
		UidColumn,
		UniqueNameColumn,
		TitleColumn,
		VisibleColumn
	};

	SectionContentListModel(QObject* parent);
	virtual ~SectionContentListModel();
	void init(B_ADS_NS::ContainerWidget* cw);

	virtual int columnCount(const QModelIndex &parent) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	virtual int rowCount(const QModelIndex &parent) const;
	virtual QVariant data(const QModelIndex &index, int role) const;

	virtual bool removeRows(int row, int count, const QModelIndex &parent);

private:
	QHash<int, QString> _headers;

	B_ADS_NS::ContainerWidget* _cw;
	QList<B_ADS_NS::SectionContent::RefPtr> _contents;
};
