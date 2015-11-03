function make(rebuild)
    if nargin < 1
        rebuild = false;
    end

    filePath = mfilename('fullpath');
    projectDir = fileparts(filePath);
    
    currentDir = pwd;
    returnToDir = onCleanup(@()cd(currentDir));
    cd(projectDir);
    
    opts = '';
    opts = [opts ' -I"' fullfile(projectDir, 'api') '"'];
    opts = [opts ' -L"' fullfile(projectDir) '" -llcr'];
    
    if ismac
        opts = [opts ' LDFLAGS="\$LDFLAGS -Xlinker -rpath -Xlinker ."'];
        opts = [opts ' CXXFLAGS="\$CXXFLAGS -std=c++11"'];
    end
    
    sourceFiles = dir(fullfile(projectDir, '*.cpp'));
    for i = 1:length(sourceFiles)
        source = sourceFiles(i);
        
        [~, name] = fileparts(source.name);
        mexname = [name '.' mexext];
        mexfile = dir(mexname);
        
        if rebuild || isempty(mexfile) || datenum(source.date) > datenum(mexfile.date)
            command = sprintf('mex %s %s', opts, source.name);
            disp(command);

            try
                eval(command);
            catch x
                disp(['Error compiling ''' source.name '''']);
                disp(x.message);
            end
        else
            disp([source.name ' is up to date']);
        end
    end
end