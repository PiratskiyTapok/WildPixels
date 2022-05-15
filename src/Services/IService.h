#pragma once
class IService
{
public:
	virtual void serve() = 0;
	virtual ~IService() = 0;
};

inline IService::~IService() {}
