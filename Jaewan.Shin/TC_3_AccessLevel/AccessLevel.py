
# Class: AccessLevel
# Method: canAccess
# Parameters: tuple (integer), integer
# Returns: string
# Method signature: def canAccess(self, rights, minPermission):

class AccessLevel:
    def canAccess(self, rights, minPermission):

        strRights = ""
        for right in rights:
            if right < minPermission:
                strRights = strRights + "D"
            else:
                strRights = strRights + "A"

        return strRights

