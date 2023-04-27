#include "Repository.h"
#include <iostream>



TrenchCoat& Repository::getObjectOnPositionCopy(int position) const
{
	return (TrenchCoat&)this->objects[position];
}


int Repository::findByLink(std::string link)
{
	int length = this->getRepositorySize();
	for (int i = 0; i < length; i++)
	{
		if (this->getObjectOnPosition(i).getPhotograph() == link)
		{
			return i;
		}
	}
	return -1;
}


//CRUD
int Repository::addObject(const TrenchCoat& object)
{
	int result;
	if (this->findByLink(object.getPhotograph()) != -1)
		result = -1;
	else
	{
		result = 1;
		this->objects.push_back(object);
	}
	return result;
}


int Repository::removeObject(const TrenchCoat& object)
{
	/*
	auto iterator = find(this->objects.begin(), this->objects.end(), object);
	if (iterator == this->objects.end())
	{
		return -1;
	}
	
	this->objects.erase(iterator);*/
	return 1;
}


int Repository::removeObjectByLink(std::string link)
{
	int position = this->findByLink(link);
	if (position == -1)
	{
		return -1;
	}
	return this->removeObject(this->getObjectOnPosition(position));
}


int Repository::updateObject(std::string link, int size_new, std::string color_new, int price_new, int quantity_new)
{
	int position = this->findByLink(link);

	if (position == -1)
	{
		return -1;
	}
	TrenchCoat& object = this->getObjectOnPositionCopy(position);
	object.setSize(size_new);
	object.setColor(color_new);
	object.setPrice(price_new);
	object.setQuantity(quantity_new);
	return 1;
}


void Repository::populate()
{
	TrenchCoat t1 = TrenchCoat(36, "Beige", 21275, 100, "https://media.dior.com/couture/ecommerce/media/catalog/product/G/B/1676656893_327M34A3332_X1700_E01_ZHC.jpg?imwidth=1080");
	this->objects.push_back(t1);
	TrenchCoat t2 = TrenchCoat(34, "Pink", 348, 10050, "https://cdn.aboutstatic.com/file/images/6de565f5258f0a18507b84a93fef3363.png?bg=F4F4F5&quality=75&trim=1&height=480&width=360");
	this->objects.push_back(t2);
	TrenchCoat t3 = TrenchCoat(36, "Black", 450, 105, "https://www.mohito.com/ro/ro/trench-elegant-cu-curea-3403u-99x?gclid=Cj0KCQjw8qmhBhClARIsANAtbocb5I8uOWTtt7Haou4_9U-s8zXWhV76MYumoJ7ZAFgqOT33O9QEVhgaAtdBEALw_wcB");
	this->objects.push_back(t3);
	TrenchCoat t4 = TrenchCoat(36, "Black", 500, 10, "https://www.zalando.ro/mango-palton-clasic-schwarz-m9121u1ad-q11.html?size=M&allophones=0&wmc=SEM400_NB_GO._3625232631_17072920796_137263143538.&opc=2211&mpp=google|v1||pla-293946777986||1011806||g|c||595096751273||pla|M9121U1AD-Q11000M000|293946777986|1|&gclid=Cj0KCQjw8qmhBhClARIsANAtbofZ6JQlAHoIAovZyPmfbc6GuX9BCC1Fpn_Kcy2a2gYYVTLXzaYJJuAaAtnJEALw_wcB");
	this->objects.push_back(t4);
	TrenchCoat t5 = TrenchCoat(38, "Black", 389, 156, "https://remixshop.com/ro/womens-clothes/coats?brand_range=MID&product_id=27349176&page_type=pdlp&utm_campaign=dynamic_ads&utm_source=google&utm_medium=cpc&utm_content=shopping_premium&utm_term=product_page&gclid=Cj0KCQjw8qmhBhClARIsANAtboekG0H6L1y-yLkHz21k08C6Q0qyLFBhSVH1niNJPUtFWQyaQmu8-wEaAq0lEALw_wcB");
	this->objects.push_back(t5);
	TrenchCoat t6 = TrenchCoat(40, "Black", 247, 105, "https://www.aboutyou.ro/p/only/palton-de-primavara-toamna-line-5570004?vid=42790679&om_channel=PLA&utm_content=ppc&utm_source=google&utm_medium=cpc&utm_campaign=PLA_RO_Mid_AP_Generic_NK_CSS_S24&gclid=Cj0KCQjw8qmhBhClARIsANAtboc60-EHLMlqH5tTAFREBMUyoD1S0f1d-Ljdi-RDK2IbSj-_LedTuhoaAgdsEALw_wcB");
	this->objects.push_back(t6);
	TrenchCoat t7 = TrenchCoat(34, "kaki", 555, 1005, "https://cdn.aboutstatic.com/file/images/6820ac993dc4ece219ccaa37f9a92438.jpg?quality=75&height=480&width=360");
	this->objects.push_back(t7);
	TrenchCoat t8 = TrenchCoat(36, "Ivory", 160, 16, "https://static.sinsay.com/media/catalog/product/3/1/3149F-01X-001-1-580435_10.jpg");
	this->objects.push_back(t8);
	TrenchCoat t9 = TrenchCoat(34, "Ivory", 160, 25, "https://static.sinsay.com/media/catalog/product/3/1/3149F-01X-003-1-585271_10.jpg");
	this->objects.push_back(t9);
	TrenchCoat t10 = TrenchCoat(36, "Pink", 115, 234, "https://media.remix.eu/files/41-2022/Damski-shlifer-Bik-Bok-117517578a.jpg");
	this->objects.push_back(t10);
}