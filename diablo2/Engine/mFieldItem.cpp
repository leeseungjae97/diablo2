#include "mFieldItem.h"
namespace m
{
	FieldItem::FieldItem(eItem item)
		: Item(itemTypeTable[(int)item])
	{}
	FieldItem::~FieldItem()
	{}
	void FieldItem::Initialize()
	{}
	void FieldItem::Update()
	{}
	void FieldItem::LateUpdate()
	{}
	void FieldItem::Render()
	{}
}