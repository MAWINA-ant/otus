#include "view.h"
#include "observ.h"
#include "model.h"

View::View(Model *m) : model{m} {
    model->addObserver(this);
}

void View::update()
{

}
