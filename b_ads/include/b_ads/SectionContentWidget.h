#pragma once

#include <QFrame>

#include "API.h"
#include "SectionContent.h"

B_ADS_NAMESPACE_BEGIN
class ContainerWidget;
class SectionWidget;

class SectionContentWidget : public QFrame
{
	Q_OBJECT

	friend class ContainerWidget;

public:
	SectionContentWidget(SectionContent::RefPtr c, QWidget* parent = 0);
	virtual ~SectionContentWidget();

private:
	SectionContent::RefPtr _content;
};

B_ADS_NAMESPACE_END
