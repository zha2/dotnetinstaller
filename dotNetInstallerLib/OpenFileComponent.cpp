#include "StdAfx.h"
#include "XmlAttribute.h"
#include "OpenFileComponent.h"
#include "InstallConfiguration.h"
#include "InstallerLog.h"
#include "InstallerSession.h"

OpenFileComponent::OpenFileComponent()
	: Component(openfile)
	, m_rc(0)
{
}

void OpenFileComponent::Exec()
{
	DVLib::ShellCmd(file, & m_rc);
}

bool OpenFileComponent::IsExecuting() const
{
	return false;
}

void OpenFileComponent::Load(TiXmlElement * node)
{
	file = XML_ATTRIBUTE(node->Attribute("file"));
	Component::Load(node);
	LOG(L"Loaded 'openfile' component '" << file << L"'");
}

int OpenFileComponent::GetExitCode() const
{
	return m_rc;
}
