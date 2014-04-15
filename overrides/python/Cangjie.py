from ..importer import modules
from ..overrides import override


Cangjie = modules["Cangjie"]._introspection_module


__all__ = []


class Char(Cangjie.Char):
    def __getattr__(self, attr):
        if attr in ("chchar", "simpchar", "code", "frequency"):
            return self.get_property(attr)

        raise AttributeError("'%s' object has no attribute '%s'"
                             % (type(self).__name__, attr))

    def __setattr__(self, attr, value):
        if attr in ("chchar", "simpchar", "code", "frequency"):
            return self.set_property(attr, value)

        Cangjie.Char.__setattr__(self, attr, value)

Char = override(Char)
__all__.append("Char")
