#ifndef _LOCATIONS_ACTIONS_
#define _LOCATIONS_ACTIONS_

#include "IControls.h"
#include "ActionsPanel.h"
#include "actioncode.h"
#include "ilocationpage.h"

namespace Ui
{
	class LocationActions :
		public QWidget
	{
	public:
		LocationActions(QWidget *parent, ILocationPage *locPage, IControls *controls);

		void LoadAllActions();

		void SelectActionInList( size_t actIndex );

	private:
		IControls *_controls;
		ILocationPage		*_locPage;

		ActionsPanel		*_actPanel;
		ActionCode			*_actCode;
	};
} // namespace Ui

#endif // _LOCATIONS_ACTIONS_

