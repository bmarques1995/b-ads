#pragma once

#include <QPointer>
#include <QPoint>
#include <QFrame>

#include "API.h"
#include "SectionContent.h"

B_ADS_NAMESPACE_BEGIN
class ContainerWidget;
class SectionWidget;
class FloatingWidget;

class SectionTitleWidget : public QFrame
{
	Q_OBJECT
	Q_PROPERTY(bool activeTab READ isActiveTab WRITE setActiveTab NOTIFY activeTabChanged)

	friend class ContainerWidget;
	friend class SectionWidget;

	SectionContent::RefPtr _content;

	// Drag & Drop (Floating)
	QPointer<FloatingWidget> _fw;
	QPoint _dragStartPos;

	// Drag & Drop (Title/Tabs)
	bool _tabMoving;

	// Property values
	bool _activeTab;

public:
	SectionTitleWidget(SectionContent::RefPtr content, QWidget* parent);
	virtual ~SectionTitleWidget();

	bool isActiveTab() const;
	void setActiveTab(bool active);

protected:
	virtual void mousePressEvent(QMouseEvent* ev);
	virtual void mouseReleaseEvent(QMouseEvent* ev);
	virtual void mouseMoveEvent(QMouseEvent* ev);

signals:
	void activeTabChanged();
	void clicked();
};

B_ADS_NAMESPACE_END
