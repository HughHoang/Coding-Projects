function isStrongPassword(thePassword) {
    if (thePassword.length < 8) {
        return false
    }
    else if (thePassword.indexOf("password") != -1) {
        return false
    }
    else if (thePassword.charAt < 65 || thePassword.charAt > 90  ) {

        return false
    }
    else {
        return true
    }
}