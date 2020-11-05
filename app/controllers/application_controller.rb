class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception


helper_method :current_user, :logged_in? #this makes sure, that current use is available also
#for ApplicationHelper, not only for ApplicationController

  def current_user
    @current_user ||= User.find(session[:user_id]) if session[:user_id]
  end

  def logged_in?
    !!current_user # this returns a boolean value, and makes sure user is on
  end

  def require_user
    if !logged_in?
      flash[:alert] = "You don't have permission to perform this operation"
      redirect_to login_path
    end
  end
end
