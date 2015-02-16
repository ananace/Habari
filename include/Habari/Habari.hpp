#pragma once

namespace Habari
{
	
enum SourceTypes
{
	Source_Default = 0,
	Source_Environment = 1,
	Source_Commandline = 2,
	Source_User = 4,

	Source_Any = Source_Environment | Source_Commandline | Source_User
};

void ParseEnvironment();
void ParseCommandline(int argc, char** argv);

bool HasErrors();
void PrintErrors();
void PrintUsage(const char* extraOptions);

bool RegisterParameter(IParameter*);
IParameter* FindParameter(const char* name);

class IParameter
{
public:
	virtual const char* getName() const = 0;
	virtual const char* getDescription() const = 0;

	virtual unsigned int numAliases() const = 0;
	virtual const char* getAlias(unsigned int i = 0) const = 0;
	virtual const char* getCategory() const = 0;
	virtual unsigned int numShorthands() const = 0;
	virtual char getShorthand(unsigned int i = 0) const = 0;
	virtual const char* getEnvironment() const = 0;

	virtual bool isSet(SourceTypes source = Source_Any) const = 0;
	virtual void setValue(const char* inp, SourceTypes) = 0;

	virtual SourceTypes getSources() const = 0;
};

}
