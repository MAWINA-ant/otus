#include "view.h"
#include "observ.h"
#include "model.h"

View::View(Model *m) : model{m} {
    model->addObserver(this);
}

void View::setModel(Model *m) {
    model = m;
    update();
}

void View::update()
{
    auto v = model->getData();
    for (auto &el : v) {
        el->draw();
    }
}
