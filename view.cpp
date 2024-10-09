#include "view.h"
#include "observ.h"
#include "model.h"

View::View(Model *m) {
    model = std::make_shared<Model>(*m);
    model->addObserver(this);
}

void View::update()
{
    auto v = model->getData();
    for (auto &el : v) {
        el->draw();
    }
}
