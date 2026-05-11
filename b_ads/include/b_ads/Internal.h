#pragma once

#include <QSharedPointer>
#include <QWeakPointer>

#include "API.h"

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#else
#include "SectionContent.h"
#endif

#define SCLookupMapById(X)   X->_scLookupMapById
#define SCLookupMapByName(X) X->_scLookupMapByName
#define SWLookupMapById(X)   X->_swLookupMapById

B_ADS_NAMESPACE_BEGIN
class SectionContent;
class SectionTitleWidget;
class SectionContentWidget;


class InternalContentData
{
public:
	typedef QSharedPointer<InternalContentData> RefPtr;
	typedef QWeakPointer<InternalContentData> WeakPtr;

	InternalContentData();
	~InternalContentData();

	QSharedPointer<SectionContent> content;
	SectionTitleWidget* titleWidget;
	SectionContentWidget* contentWidget;
};


class HiddenSectionItem
{
public:
	HiddenSectionItem() :
		preferredSectionId(-1),
		preferredSectionIndex(-1)
	{}

	int preferredSectionId;
	int preferredSectionIndex;
	InternalContentData data;
};


B_ADS_NAMESPACE_END
